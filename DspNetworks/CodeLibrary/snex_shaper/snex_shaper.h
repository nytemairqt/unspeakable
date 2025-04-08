template <int NumVoices> struct snex_shaper
{
	SNEX_NODE(snex_shaper);
	
	int MODE = 0;
	double sr = 0.0;
	
	// typeA: Reference – basic combination of tanh and quadratic shaping.
	float typeA(float input)
	{
	    float x = input;
	    x = x + (Math.tanh(x) + Math.pow(x, 2.0));
	    x *= 0.1f;
	    return x;
	}
	
	// typeB: Asymmetric waveshaper using an if‑statement.
	float typeB(float input)
	{
	    float x = input;
	    if (x < 0.0f)
	    {
	        // For negative values, apply a slightly stronger tanh offset.
	        x = Math.tanh(x + 0.2f) + 0.3f * Math.pow(x, 2.0);
	    }
	    else
	    {
	        // For non-negative values, apply a milder offset.
	        x = Math.tanh(x - 0.2f) + 0.3f * Math.pow(x, 2.0);
	    }
	    x *= 0.6f;
	    return x;
	}
	
	// typeC: Asymmetric shaping using different polynomial curves on each half.
	float typeC(float input)
	{
	    float x = input;
	    if (x < 0.0f)
	    {
	        // Negative: emphasize odd-power distortion.
	        x = Math.tanh(x) - 0.2f * Math.pow(x, 3.0);
	    }
	    else
	    {
	        // Positive: add an even-power term for warmth.
	        x = Math.tanh(x) + 0.2f * Math.pow(x, 2.0);
	    }
	    x *= 0.6f;
	    return x;
	}
	
	// typeD: Uses if‑statements and a mix of tanh and sin modulation.
	float typeD(float input)
	{
	    float x = input;
	    if (x < 0.0f)
	    {
	        x = Math.tanh(x + 0.1f) + 0.25f * Math.sin(x * 2.0);
	    }
	    else
	    {
	        x = Math.tanh(x - 0.1f) + 0.25f * Math.sin(x * 2.0);
	    }
	    x *= 0.6f;
	    return x;
	}
	
	// typeE: Blends shifted tanh with cosine modulation, with an if‑branch for asymmetry.
	float typeE(float input)
	{
	    float x = input;
	    if (x < 0.0f)
	    {
	        x = Math.tanh(x + 0.15f) + 0.3f * Math.cos(x * 2.0);
	    }
	    else
	    {
	        x = Math.tanh(x - 0.15f) + 0.3f * Math.cos(x * 2.0);
	    }
	    x *= 0.6f;
	    return x;
	}
	
	// typeF: Uses a symmetric tanh blend with an added asymmetric quadratic term.
	float typeF(float input)
	{
	    float x = input;
	    if (x < 0.0f)
	    {
	        x = Math.tanh(x) + 0.35f * Math.pow(x, 2.0);
	    }
	    else
	    {
	        x = Math.tanh(x) + 0.25f * Math.pow(x, 2.0);
	    }
	    x *= 0.6f;
	    return x;
	}
	
	// typeG: Introduces asymmetry by applying a sine modulation only on positive values.
	float typeG(float input)
	{
	    float x = input;
	    if (x >= 0.0f)
	    {
	        x = Math.tanh(x) + 0.3f * Math.sin(x * 2.0) + 0.2f * Math.pow(x, 2.0);
	    }
	    else
	    {
	        x = Math.tanh(x) + 0.2f * Math.pow(x, 2.0);
	    }
	    x *= 0.6f;
	    return x;
	}
	
	// typeH: Asymmetric blend with different cosine curves for negative and positive.
	float typeH(float input)
	{
	    float x = input;
	    if (x < 0.0f)
	    {
	        x = Math.tanh(x + 0.1f) - 0.2f * Math.cos(x * 2.0);
	    }
	    else
	    {
	        x = Math.tanh(x - 0.1f) + 0.2f * Math.cos(x * 2.0);
	    }
	    x *= 0.6f;
	    return x;
	}
	
	// typeI: Combines an if‑branch with polynomial terms and a tangent modulation.
	float typeI(float input)
	{
	    float x = input;
	    if (x < 0.0f)
	    {
	        x = Math.tanh(x + 0.2f) + 0.15f * Math.pow(x, 2.0) - 0.1f * Math.tan(x * 1.5);
	    }
	    else
	    {
	        x = Math.tanh(x - 0.2f) + 0.15f * Math.pow(x, 2.0) + 0.1f * Math.tan(x * 1.5);
	    }
	    x *= 0.6f;
	    return x;
	}
	
	// typeJ: Uses if‑statements to blend tanh and polynomial distortion with sine modulation.
	float typeJ(float input)
	{
	    float x = input;
	    if (x < 0.0f)
	    {
	        x = Math.tanh(x) - 0.25f * Math.pow(x, 3.0) + 0.15f * Math.sin(x * 2.0);
	    }
	    else
	    {
	        x = Math.tanh(x) + 0.25f * Math.pow(x, 2.0) + 0.15f * Math.sin(x * 2.0);
	    }
	    x *= 0.6f;
	    return x;
	}
	
	// typeK: Combines cosine and tanh with an asymmetric polynomial offset.
	float typeK(float input)
	{
	    float x = input;
	    if (x < 0.0f)
	    {
	        x = Math.tanh(x + 0.1f) + 0.35f * Math.pow(x, 2.0) - 0.1f * Math.cos(x * 2.0);
	    }
	    else
	    {
	        x = Math.tanh(x - 0.1f) + 0.35f * Math.pow(x, 2.0) + 0.1f * Math.cos(x * 2.0);
	    }
	    x *= 0.6f;
	    return x;
	}
	
	// typeL: Uses an if‑statement to apply a random offset on the negative side.
	float typeL(float input)
	{
	    float x = input;
	    if (x < 0.0f)
	    {
	        x = Math.tanh(x + 0.2f) + 0.3f * Math.pow(x, 2.0);
	    }
	    else
	    {
	        x = Math.tanh(x) + 0.3f * Math.pow(x, 2.0);
	    }
	    x *= 0.6f;
	    return x;
	}
	
	// typeM: Adds an extra high-order term on the positive side.
	float typeM(float input)
	{
	    float x = input;
	    if (x < 0.0f)
	    {
	        x = Math.tanh(x) + 0.25f * Math.pow(x, 2.0);
	    }
	    else
	    {
	        x = Math.tanh(x) + 0.25f * Math.pow(x, 2.0) + 0.1f * Math.pow(x, 5.0);
	    }
	    x *= 0.6f;
	    return x;
	}
	
	// typeN: Uses cosine modulation in an if‑branch to simulate analog behavior.
	float typeN(float input)
	{
	    float x = input;
	    if (x < 0.0f)
	    {
	        x = Math.tanh(x + 0.15f) + 0.2f * Math.cos(x * 2.0);
	    }
	    else
	    {
	        x = Math.tanh(x - 0.15f) + 0.2f * Math.cos(x * 2.0);
	    }
	    x *= 0.6f;
	    return x;
	}
	
	// typeO: Combines a symmetric tanh curve with asymmetric sine addition.
	float typeO(float input)
	{
	    float x = input;
	    if (x < 0.0f)
	    {
	        x = Math.tanh(x) - 0.2f * Math.sin(x * 2.0);
	    }
	    else
	    {
	        x = Math.tanh(x) + 0.2f * Math.sin(x * 2.0);
	    }
	    x *= 0.6f;
	    return x;
	}
	
	// typeP: Uses an if‑statement to apply different power curves for negative and positive values.
	float typeP(float input)
	{
	    float x = input;
	    if (x < 0.0f)
	    {
	        x = Math.tanh(x) - 0.3f * Math.pow(x, 3.0);
	    }
	    else
	    {
	        x = Math.tanh(x) + 0.3f * Math.pow(x, 2.0);
	    }
	    x *= 0.6f;
	    return x;
	}
	
	// typeQ: Incorporates a randomized element (using Math.randomDouble()) on the positive side.
	float typeQ(float input)
	{
	    float x = input;
	    if (x < 0.0f)
	    {
	        x = Math.tanh(x) + 0.25f * Math.pow(x, 2.0);
	    }
	    else
	    {
	        // Apply a random offset between 0 and 0.1.
	        float r = (float) Math.randomDouble() * 0.1f;
	        x = Math.tanh(x + r) + 0.25f * Math.pow(x, 2.0);
	    }
	    x *= 0.6f;
	    return x;
	}
	
	// typeR: Emphasizes even harmonics with an if‑statement to slightly alter symmetry.
	float typeR(float input)
	{
	    float x = input;
	    if (x < 0.0f)
	    {
	        x = x + 0.25f * Math.pow(x, 2.0) + 0.1f * Math.pow(x, 4.0);
	    }
	    else
	    {
	        x = x + 0.25f * Math.pow(x, 2.0) + 0.1f * Math.pow(x, 4.0);
	    }
	    x *= 0.6f;
	    return x;
	}
	
	// typeS: Subtractive waveshaping with an if‑branch to control high‑end harshness.
	float typeS(float input)
	{
	    float x = input;
	    if (x < 0.0f)
	    {
	        x = Math.tanh(x) - 0.1f * Math.pow(x, 4.0);
	    }
	    else
	    {
	        x = Math.tanh(x) + 0.1f * Math.pow(x, 4.0);
	    }
	    x *= 0.6f;
	    return x;
	}
	
	// typeT: Combines multiple nonlinear functions with a randomized cubic modifier.
	float typeT(float input)
	{
	    float x = input;
	    float r = (float) Math.randomDouble() * 0.05f;
	    if (x < 0.0f)
	    {
	        x = Math.tanh(x + 0.1f) + 0.3f * Math.pow(x, 2.0) - 0.1f * Math.pow(x, 3.0 + r);
	    }
	    else
	    {
	        x = Math.tanh(x - 0.1f) + 0.3f * Math.pow(x, 2.0) - 0.1f * Math.pow(x, 3.0 + r);
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
				if (MODE == 5)
					s = typeF(s);
				if (MODE == 6)
					s = typeG(s);
				if (MODE == 7)
					s = typeH(s);
				if (MODE == 8)
					s = typeI(s);
				if (MODE == 9)
					s = typeJ(s);
				if (MODE == 10)
					s = typeK(s);
				if (MODE == 11)
					s = typeL(s);
				if (MODE == 12)
					s = typeM(s);
				if (MODE == 13)
					s = typeN(s);
				if (MODE == 14)
					s = typeO(s);
				if (MODE == 15)
					s = typeP(s);
				if (MODE == 16)
					s = typeQ(s);
				if (MODE == 17)
					s = typeR(s);
				if (MODE == 18)
					s = typeS(s);
				if (MODE == 19)
					s = typeT(s);
					
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
			if (MODE == 5)
				s = typeF(s);
			if (MODE == 6)
				s = typeG(s);
			if (MODE == 7)
				s = typeH(s);
			if (MODE == 8)
				s = typeI(s);
			if (MODE == 9)
				s = typeJ(s);
			if (MODE == 10)
				s = typeK(s);
			if (MODE == 11)
				s = typeL(s);
			if (MODE == 12)
				s = typeM(s);
			if (MODE == 13)
				s = typeN(s);
			if (MODE == 14)
				s = typeO(s);
			if (MODE == 15)
				s = typeP(s);
			if (MODE == 16)
				s = typeQ(s);
			if (MODE == 17)
				s = typeR(s);
			if (MODE == 18)
				s = typeS(s);
			if (MODE == 19)
				s = typeT(s);
				
			s *= 5.0f;

			//s = typeB(s);
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
