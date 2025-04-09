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
