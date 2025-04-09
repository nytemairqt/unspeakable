Content.makeFrontInterface(700, 100);

const knbControls = [Content.getComponent("knbInputGain"), Content.getComponent("knbOutputGain"), Content.getComponent("knbMode"), Content.getComponent("knbClarity")];
const scriptFX = Synth.getEffect("scriptFX");


const eq = [Synth.getEffect("eqA"), Synth.getEffect("eqB"), Synth.getEffect("eqC"), Synth.getEffect("eqD")];

inline function toggleEQ(index)
{
	for (i=0; i<eq.length; i++)
		if (i != index)
			eq[i].setBypassed(1);
	eq[index].setBypassed(0);
}

inline function onknbControl(component, value)
{
	switch (component)
	{
		case knbControls[0]: // Input Gain
			scriptFX.setAttribute(scriptFX.inputGain, value);
			break;
		case knbControls[1]: // Output Gain
			scriptFX.setAttribute(scriptFX.outputGain, value);
			break;
		case knbControls[2]: // Mode
			toggleEQ(value);
			scriptFX.setAttribute(scriptFX.mode, value);			
			break;
		case knbControls[3]: // Clarity
			scriptFX.setAttribute(scriptFX.clarity, value);
			break;
	}
}

for (k in knbControls)
	k.setControlCallback(onknbControl);function onNoteOn()
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
 