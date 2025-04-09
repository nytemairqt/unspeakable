#pragma once

// These will improve the readability of the connection definition

#define getT(Idx) template get<Idx>()
#define connectT(Idx, target) template connect<Idx>(target)
#define getParameterT(Idx) template getParameter<Idx>()
#define setParameterT(Idx, value) template setParameter<Idx>(value)
#define setParameterWT(Idx, value) template setWrapParameter<Idx>(value)
using namespace scriptnode;
using namespace snex;
using namespace snex::Types;

namespace UnspeakableDSP_impl
{
// ==============================| Node & Parameter type declarations |==============================

DECLARE_PARAMETER_RANGE_SKEW(envelope_follower_modRange, 
                             0., 
                             16., 
                             5.42227);

template <int NV>
using envelope_follower_mod = parameter::from0To1<core::gain<NV>, 
                                                  0, 
                                                  envelope_follower_modRange>;

template <int NV>
using envelope_follower_t = wrap::mod<envelope_follower_mod<NV>, 
                                      wrap::no_data<dynamics::envelope_follower<NV>>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, envelope_follower_t<NV>>, 
                                 core::gain<NV>>;
template <int NumVoices> struct snex_shaper
{
	SNEX_NODE(snex_shaper);
	int MODE = 0;
	double sr = 0.0;
	// A - Simple Pi Clipper
	float typeA(float input)
	{
		float x = input;
		float pi = 3.14159266f;
		if (x > pi)
			x = pi;
		return x;
	}
	// B - Tape Drive
	float typeB(float input)
	{
		float x = input;
		if (x > 0.0f)
			x = Math.tanh(x + (Math.pow(x, 2)) * 0.77f);
		else
			x = Math.sin(x + (Math.pow(x, 2)) * 0.77f + (Math.pow(x, 3)) * 0.20f);
		return x;
	}
	// C - Asymmetric Polynomial
	float typeC(float input)
	{
		float x = input;
		x *= 2.5f;
		if (x > 0.0f)
			x = Math.tanh((1.0f * Math.pow(x, 2)) + (0.2f * Math.pow(x, 4)));
		else
			x = Math.tanh(x) + (0.35f * Math.pow(x, 3));
		return x;
	}
	// D - Modified Waveshaper
	float typeD(float input)
	{
		float x = input;
		float dr = (2.0f * 0.22f / (1.0f - 0.22f));
		x = (1.0f + dr) * x / (1.0f + dr * Math.abs(x));
		return x;
	}
	// These functions are the glue code that call the function above
	template <typename T> void process(T& data)
	{
		for(auto ch: data)
		{
			for(auto& s: data.toChannelData(ch))
			{
				if (MODE == 0)
					s = typeA(s);
				if (MODE == 1)
					s = typeB(s);
				if (MODE == 2)
					s = typeC(s);
				if (MODE == 3)
					s = typeD(s);
			}
		}
	}
	template <typename T> void processFrame(T& data)
	{
		for(auto& s: data)
		{
			if (MODE == 0)
				s = typeA(s);
			if (MODE == 1)
				s = typeB(s);
			if (MODE == 2)
				s = typeC(s);
			if (MODE == 3)
				s = typeD(s);
		}
	}
	void prepare(PrepareSpecs ps)
	{
		sr = ps.sampleRate;
	}
	template <int P> void setParameter(double v)
	{
		if (P == 0) // Mode
			MODE = (int)v;
	}
	void reset(){}
	void setExternalData(const ExternalData& d, int index){}
};

template <int NV>
using snex_shaper_t = wrap::no_data<core::snex_shaper<snex_shaper<NV>>>;

template <int NV>
using oversample4x_t_ = container::chain<parameter::empty, 
                                         wrap::fix<2, snex_shaper_t<NV>>>;

template <int NV>
using oversample4x_t = wrap::oversample<4, oversample4x_t_<NV>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<2, filters::svf_eq<NV>>, 
                                  filters::svf_eq<NV>, 
                                  filters::svf_eq<NV>>;

DECLARE_PARAMETER_RANGE(pma_mod_0Range, 
                        0., 
                        9.);

template <int NV>
using pma_mod_0 = parameter::from0To1<filters::svf_eq<NV>, 
                                      2, 
                                      pma_mod_0Range>;

DECLARE_PARAMETER_RANGE_INV(pma_mod_1Range, 
                            -6., 
                            0.);

template <int NV>
using pma_mod_1 = parameter::from0To1_inv<filters::svf_eq<NV>, 
                                          2, 
                                          pma_mod_1Range>;

DECLARE_PARAMETER_RANGE(pma_mod_2Range, 
                        0., 
                        12.);

template <int NV>
using pma_mod_2 = parameter::from0To1<filters::svf_eq<NV>, 
                                      2, 
                                      pma_mod_2Range>;

template <int NV>
using pma_mod = parameter::chain<ranges::Identity, 
                                 pma_mod_0<NV>, 
                                 pma_mod_1<NV>, 
                                 pma_mod_2<NV>>;

template <int NV>
using pma_t = control::pma<NV, pma_mod<NV>>;
template <int NV>
using envelope_follower1_t = wrap::mod<parameter::plain<pma_t<NV>, 0>, 
                                       wrap::no_data<dynamics::envelope_follower<NV>>>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<2, filters::one_pole<NV>>, 
                                  filters::one_pole<NV>, 
                                  envelope_follower1_t<NV>, 
                                  pma_t<NV>, 
                                  math::mul<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, chain1_t<NV>>, 
                                 chain2_t<NV>>;

namespace UnspeakableDSP_t_parameters
{
// Parameter list for UnspeakableDSP_impl::UnspeakableDSP_t ----------------------------------------

template <int NV>
using inputGain = parameter::plain<core::gain<NV>, 0>;
template <int NV> using outputGain = inputGain<NV>;
template <int NV>
using mode = parameter::plain<UnspeakableDSP_impl::snex_shaper_t<NV>, 
                              0>;
template <int NV>
using clarity = parameter::plain<UnspeakableDSP_impl::pma_t<NV>, 
                                 1>;
template <int NV>
using UnspeakableDSP_t_plist = parameter::list<inputGain<NV>, 
                                               outputGain<NV>, 
                                               mode<NV>, 
                                               clarity<NV>>;
}

template <int NV>
using UnspeakableDSP_t_ = container::chain<UnspeakableDSP_t_parameters::UnspeakableDSP_t_plist<NV>, 
                                           wrap::fix<2, core::gain<NV>>, 
                                           chain_t<NV>, 
                                           oversample4x_t<NV>, 
                                           split_t<NV>, 
                                           core::gain<NV>, 
                                           core::gain<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public UnspeakableDSP_impl::UnspeakableDSP_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(UnspeakableDSP);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(68)
		{
			0x005B, 0x0000, 0x6900, 0x706E, 0x7475, 0x6147, 0x6E69, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x0042, 0x0000, 0x0000, 0x8000, 0x0A3F, 
            0x23D7, 0x5B3C, 0x0001, 0x0000, 0x756F, 0x7074, 0x7475, 0x6147, 
            0x6E69, 0x0000, 0xC800, 0x00C2, 0x0000, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x0A3F, 0x23D7, 0x5B3C, 0x0002, 0x0000, 0x6F6D, 0x6564, 
            0x0000, 0x0000, 0x0000, 0x4000, 0x0040, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x8000, 0x5B3F, 0x0003, 0x0000, 0x6C63, 0x7261, 0x7469, 
            0x0079, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0xD70A, 0x3C23, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& gain2 = this->getT(0);                              // core::gain<NV>
		auto& chain = this->getT(1);                              // UnspeakableDSP_impl::chain_t<NV>
		auto& envelope_follower = this->getT(1).getT(0);          // UnspeakableDSP_impl::envelope_follower_t<NV>
		auto& gain = this->getT(1).getT(1);                       // core::gain<NV>
		auto& oversample4x = this->getT(2);                       // UnspeakableDSP_impl::oversample4x_t<NV>
		auto& snex_shaper = this->getT(2).getT(0);                // UnspeakableDSP_impl::snex_shaper_t<NV>
		auto& split = this->getT(3);                              // UnspeakableDSP_impl::split_t<NV>
		auto& chain1 = this->getT(3).getT(0);                     // UnspeakableDSP_impl::chain1_t<NV>
		auto& svf_eq = this->getT(3).getT(0).getT(0);             // filters::svf_eq<NV>
		auto& svf_eq2 = this->getT(3).getT(0).getT(1);            // filters::svf_eq<NV>
		auto& svf_eq1 = this->getT(3).getT(0).getT(2);            // filters::svf_eq<NV>
		auto& chain2 = this->getT(3).getT(1);                     // UnspeakableDSP_impl::chain2_t<NV>
		auto& one_pole = this->getT(3).getT(1).getT(0);           // filters::one_pole<NV>
		auto& one_pole1 = this->getT(3).getT(1).getT(1);          // filters::one_pole<NV>
		auto& envelope_follower1 = this->getT(3).getT(1).getT(2); // UnspeakableDSP_impl::envelope_follower1_t<NV>
		auto& pma = this->getT(3).getT(1).getT(3);                // UnspeakableDSP_impl::pma_t<NV>
		auto& mul = this->getT(3).getT(1).getT(4);                // math::mul<NV>
		auto& gain1 = this->getT(4);                              // core::gain<NV>
		auto& gain3 = this->getT(5);                              // core::gain<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, gain2); // inputGain -> gain2::Gain
		
		this->getParameterT(1).connectT(0, gain3); // outputGain -> gain3::Gain
		
		this->getParameterT(2).connectT(0, snex_shaper); // mode -> snex_shaper::mode
		
		this->getParameterT(3).connectT(0, pma); // clarity -> pma::Multiply
		
		// Modulation Connections ------------------------------------------------------------------
		
		envelope_follower.getParameter().connectT(0, gain);         // envelope_follower -> gain::Gain
		pma.getWrappedObject().getParameter().connectT(0, svf_eq);  // pma -> svf_eq::Gain
		pma.getWrappedObject().getParameter().connectT(1, svf_eq2); // pma -> svf_eq2::Gain
		pma.getWrappedObject().getParameter().connectT(2, svf_eq1); // pma -> svf_eq1::Gain
		envelope_follower1.getParameter().connectT(0, pma);         // envelope_follower1 -> pma::Value
		
		// Default Values --------------------------------------------------------------------------
		
		;                            // gain2::Gain is automated
		gain2.setParameterT(1, 20.); // core::gain::Smoothing
		gain2.setParameterT(2, 0.);  // core::gain::ResetValue
		
		envelope_follower.setParameterT(0, 20.); // dynamics::envelope_follower::Attack
		envelope_follower.setParameterT(1, 20.); // dynamics::envelope_follower::Release
		envelope_follower.setParameterT(2, 0.);  // dynamics::envelope_follower::ProcessSignal
		
		;                           // gain::Gain is automated
		gain.setParameterT(1, 20.); // core::gain::Smoothing
		gain.setParameterT(2, 0.);  // core::gain::ResetValue
		
		oversample4x.setParameterT(0, 0.); // container::chain::FilterType
		
		; // snex_shaper::mode is automated
		
		svf_eq.setParameterT(0, 4188.96);  // filters::svf_eq::Frequency
		svf_eq.setParameterT(1, 0.675496); // filters::svf_eq::Q
		;                                  // svf_eq::Gain is automated
		svf_eq.setParameterT(3, 0.01);     // filters::svf_eq::Smoothing
		svf_eq.setParameterT(4, 4.);       // filters::svf_eq::Mode
		svf_eq.setParameterT(5, 1.);       // filters::svf_eq::Enabled
		
		svf_eq2.setParameterT(0, 6411.55); // filters::svf_eq::Frequency
		svf_eq2.setParameterT(1, 1.55855); // filters::svf_eq::Q
		;                                  // svf_eq2::Gain is automated
		svf_eq2.setParameterT(3, 0.01);    // filters::svf_eq::Smoothing
		svf_eq2.setParameterT(4, 4.);      // filters::svf_eq::Mode
		svf_eq2.setParameterT(5, 1.);      // filters::svf_eq::Enabled
		
		svf_eq1.setParameterT(0, 11562.5); // filters::svf_eq::Frequency
		svf_eq1.setParameterT(1, 0.32738); // filters::svf_eq::Q
		;                                  // svf_eq1::Gain is automated
		svf_eq1.setParameterT(3, 0.01);    // filters::svf_eq::Smoothing
		svf_eq1.setParameterT(4, 3.);      // filters::svf_eq::Mode
		svf_eq1.setParameterT(5, 1.);      // filters::svf_eq::Enabled
		
		one_pole.setParameterT(0, 5295.93); // filters::one_pole::Frequency
		one_pole.setParameterT(1, 2.0899);  // filters::one_pole::Q
		one_pole.setParameterT(2, 0.);      // filters::one_pole::Gain
		one_pole.setParameterT(3, 0.01);    // filters::one_pole::Smoothing
		one_pole.setParameterT(4, 0.);      // filters::one_pole::Mode
		one_pole.setParameterT(5, 1.);      // filters::one_pole::Enabled
		
		one_pole1.setParameterT(0, 3241.15); // filters::one_pole::Frequency
		one_pole1.setParameterT(1, 1.81004); // filters::one_pole::Q
		one_pole1.setParameterT(2, 0.);      // filters::one_pole::Gain
		one_pole1.setParameterT(3, 0.01);    // filters::one_pole::Smoothing
		one_pole1.setParameterT(4, 1.);      // filters::one_pole::Mode
		one_pole1.setParameterT(5, 1.);      // filters::one_pole::Enabled
		
		envelope_follower1.setParameterT(0, 20.); // dynamics::envelope_follower::Attack
		envelope_follower1.setParameterT(1, 20.); // dynamics::envelope_follower::Release
		envelope_follower1.setParameterT(2, 0.);  // dynamics::envelope_follower::ProcessSignal
		
		;                         // pma::Value is automated
		;                         // pma::Multiply is automated
		pma.setParameterT(2, 0.); // control::pma::Add
		
		mul.setParameterT(0, 0.); // math::mul::Value
		
		gain1.setParameterT(0, -10.); // core::gain::Gain
		gain1.setParameterT(1, 20.);  // core::gain::Smoothing
		gain1.setParameterT(2, 0.);   // core::gain::ResetValue
		
		;                            // gain3::Gain is automated
		gain3.setParameterT(1, 20.); // core::gain::Smoothing
		gain3.setParameterT(2, 0.);  // core::gain::ResetValue
		
		this->setParameterT(0, 0.);
		this->setParameterT(1, 0.);
		this->setParameterT(2, 0.);
		this->setParameterT(3, 0.);
		this->setExternalData({}, -1);
	}
	~instance() override
	{
		// Cleanup external data references --------------------------------------------------------
		
		this->setExternalData({}, -1);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool hasTail() { return true; };
	
	static constexpr bool isSuspendedOnSilence() { return false; };
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(1).getT(0).setExternalData(b, index);         // UnspeakableDSP_impl::envelope_follower_t<NV>
		this->getT(2).getT(0).setExternalData(b, index);         // UnspeakableDSP_impl::snex_shaper_t<NV>
		this->getT(3).getT(1).getT(2).setExternalData(b, index); // UnspeakableDSP_impl::envelope_follower1_t<NV>
	}
};
}

#undef getT
#undef connectT
#undef setParameterT
#undef setParameterWT
#undef getParameterT
// ======================================| Public Definition |======================================

namespace project
{
// polyphonic template declaration

template <int NV>
using UnspeakableDSP = wrap::node<UnspeakableDSP_impl::instance<NV>>;
}


