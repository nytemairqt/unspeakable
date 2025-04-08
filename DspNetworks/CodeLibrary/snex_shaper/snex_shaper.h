template <int NumVoices> struct snex_shaper
{
	SNEX_NODE(snex_shaper);
	
	int MODE = 0;
	double sr = 0.0;
	
	// A - Pleasant Warm
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
	    	x = x + Math.tanh(Math.pow(x, 2));
	    else
	    	x = x + Math.sin(Math.pow(x, 2));
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
	
	// D - Broken Circuit 03
	float typeD(float input)
	{
	    float x = input;
	    float pi = 3.14159266f;
	    x *= 12.0f;
	    if (x > pi)
		   	x = (pi / 2.0f) + (0.1f * Math.pow(x, 2)) * .1f;
		else
			x = Math.sin(x) + (0.35f * Math.tanh(x + pi)) + (0.5f * Math.pow(x, 3));
	    x *= 0.02f;
	    return x;
	}
	
	// E - Powerful Drive
	float typeE(float input)
	{
	    float x = input;
	    if (x < 0.0f)
	    {
			x *= .1f;
	        x = 0.0f-Math.cos(x);
	        //x = Math.sin(x);
	    }
	    else
	    {
	        x = Math.tanh(x - 0.15f) + 0.3f * Math.cos(x * 2.0);
	    }
	    x *= 0.6f;
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
				if (MODE == 4)
					s = typeE(s);
					
				s *= 5.0f;
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
			if (MODE == 4)
				s = typeE(s);
				
			s *= 5.0f;
		}
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
