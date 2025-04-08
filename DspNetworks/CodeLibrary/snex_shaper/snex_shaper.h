template <int NumVoices> struct snex_shaper
{
	SNEX_NODE(snex_shaper);
	
	int MODE = 0;
	double sr = 0.0;
	
	// Implement the Waveshaper here...
	
	float getSample(float input)
	{
		// can't access params inside the process block
		/*
		if (MODE == 0)
		{
			input *= .5;
			return input;
		}
		*/
		
		return input;	
	}

	float typeA(float input)
	{
		return input * .1f;
	}
	// These functions are the glue code that call the function above
	template <typename T> void process(T& data)
	{
		for(auto ch: data)
		{
			for(auto& s: data.toChannelData(ch))
			{
				if (MODE == 0)
					s = getSample(s);
				if (MODE == 1)
					s = typeA(s);
			}
		}
	}
	
	template <typename T> void processFrame(T& data)
	{
		for(auto& s: data)
		{
			s = s;
		}
			//s = getSample(s);
	}
		
	void prepare(PrepareSpecs ps)
	{
		sr = ps.sampleRate;
	}
	
	template <int P> void setParameter(double v)
	{
		if (P == 0) // Mode
		{
			MODE = (int)v;
		}
	}
	
	void reset(){}
	void setExternalData(const ExternalData& d, int index){}
};
