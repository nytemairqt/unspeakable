Content.makeFrontInterface(700, 160);

// Declare Const
const knb = [Content.getComponent("knbInputGain"), Content.getComponent("knbOutputGain"), Content.getComponent("knbMode"), Content.getComponent("knbClarity")];
const btn = [Content.getComponent("btnEQOff"), Content.getComponent("btnEQA"), Content.getComponent("btnEQB"), Content.getComponent("btnEQC")];
const scriptFX = Synth.getEffect("scriptFX");
const eq = [Synth.getEffect("eqA"), Synth.getEffect("eqB"), Synth.getEffect("eqC")];

// Functionality

inline function onknbControl(component, value)
{
	switch (component)
	{
		case knb[0]: // Input Gain
			scriptFX.setAttribute(scriptFX.inputGain, value);
			break;
		case knb[1]: // Output Gain
			scriptFX.setAttribute(scriptFX.outputGain, value);
			break;
		case knb[2]: // Mode
			scriptFX.setAttribute(scriptFX.mode, value);			
			break;
		case knb[3]: // Clarity
			scriptFX.setAttribute(scriptFX.clarity, value);
			break;
	}
}

for (k in knb)
	k.setControlCallback(onknbControl);
	
inline function toggleEQ(index)
{
	for (i=0; i<eq.length; i++)
		if (i != index)
			eq[i].setBypassed(1);
	eq[index].setBypassed(0);
}
	
inline function onbtnControl(component, value)
{
	if (value)
		switch (component)
		{
			case btn[0]: // Bypass
				for (e in eq)
					e.setBypassed(1);
				break;
			case btn[1]: // A
				toggleEQ(0);
				break;
			case btn[2]: // B
				toggleEQ(1);
				break;
			case btn[3]: // C
				toggleEQ(2);
				break;
		}
}

for (b in btn)
	b.setControlCallback(onbtnControl);function onNoteOn()
{
	
}
 function onNoteOff()
{
	
}
 function onController()
{
	
}
 function onTimer()
{
	
}
 function onControl(number, value)
{
	
}
 