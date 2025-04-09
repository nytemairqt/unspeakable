Content.makeFrontInterface(700, 100);

const knbControls = [Content.getComponent("knbInputGain"), Content.getComponent("knbOutputGain"), Content.getComponent("knbMode"), Content.getComponent("knbClarity")];
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
		case knbControls[2]: // Mode
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
 