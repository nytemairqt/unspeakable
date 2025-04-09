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

namespace dsp_impl
{
// =====================| Node & Parameter type declarations |=====================

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
using dsp__t = wrap::no_data<core::snex_shaper<snex_shaper<NV>>>;

namespace dsp_t_parameters
{
}

template <int NV>
using dsp_t_ = container::chain<parameter::plain<dsp_impl::dsp__t<NV>, 0>, 
                                wrap::fix<2, dsp__t<NV>>>;

// ========================| Root node initialiser class |========================

template <int NV> struct instance: public dsp_impl::dsp_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(dsp);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(16)
		{
			0x005B, 0x0000, 0x6D00, 0x646F, 0x0065, 0x0000, 0x0000, 0x0000, 
            0x4040, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------
		
		auto& dsp_ = this->getT(0); // dsp_impl::dsp__t<NV>
		
		// Parameter Connections -------------------------------------------------
		
		this->getParameterT(0).connectT(0, dsp_); // mode -> dsp_::mode
		
		// Default Values --------------------------------------------------------
		
		; // dsp_::mode is automated
		
		this->setParameterT(0, 0.);
		this->setExternalData({}, -1);
	}
	~instance() override
	{
		// Cleanup external data references --------------------------------------
		
		this->setExternalData({}, -1);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool hasTail() { return true; };
	
	static constexpr bool isSuspendedOnSilence() { return false; };
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------
		
		this->getT(0).setExternalData(b, index); // dsp_impl::dsp__t<NV>
	}
};
}

#undef getT
#undef connectT
#undef setParameterT
#undef setParameterWT
#undef getParameterT
// =============================| Public Definition |=============================

namespace project
{
// polyphonic template declaration

template <int NV>
using dsp = wrap::node<dsp_impl::instance<NV>>;
}


