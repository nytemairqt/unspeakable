Content.makeFrontInterface(350, 100);

const knbControls = [Content.getComponent("knbInputGain"), Content.getComponent("knbOutputGain")]
const scriptFX = Synth.getEffect("scriptFX");


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
 