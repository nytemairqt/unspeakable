//Content.makeFrontInterface(540, 280);
Content.makeFrontInterface(810, 420);

include("lookAndFeel.js");

// Declare Const
const knb = [Content.getComponent("knbInputGain"), Content.getComponent("knbOutputGain"), Content.getComponent("knbMode"), Content.getComponent("knbClarity")];
const btn = [Content.getComponent("btnEQOff"), Content.getComponent("btnEQA"), Content.getComponent("btnEQB"), Content.getComponent("btnEQC")];
const lbl = [Content.getComponent("lblInputGainValue"), Content.getComponent("lblOutputGainValue"), Content.getComponent("lblModeValue"), Content.getComponent("lblClarityValue")];
const modes = ["A", "B", "C", "D"];
const scriptFX = Synth.getEffect("scriptFX");
const eq = [Synth.getEffect("eqA"), Synth.getEffect("eqB"), Synth.getEffect("eqC")];

// Functionality

inline function onknbControl(component, value)
{
	switch (component)
	{
		case knb[0]: // Input Gain
			scriptFX.setAttribute(scriptFX.inputGain, value);
			lbl[0].set("text", Engine.doubleToString(value, 2) + "dB");
			break;
		case knb[1]: // Output Gain
			scriptFX.setAttribute(scriptFX.outputGain, value);
			lbl[1].set("text", Engine.doubleToString(value, 2) + "dB");
			break;
		case knb[2]: // Mode
			scriptFX.setAttribute(scriptFX.mode, value);			
			lbl[2].set("text", modes[value]);
			break;
		case knb[3]: // Clarity
			scriptFX.setAttribute(scriptFX.clarity, value);
			lbl[3].set("text", Math.round(value * 100) + "%");
			break;
	}
}

for (k in knb)
	k.setControlCallback(onknbControl);
knb[0].setLocalLookAndFeel(lafSliderA);
knb[1].setLocalLookAndFeel(lafSliderB);
knb[2].setLocalLookAndFeel(lafSliderC);
knb[3].setLocalLookAndFeel(lafSliderD);
	
	
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
{
	b.setControlCallback(onbtnControl);
	b.setLocalLookAndFeel(lafButton);
}
	function onNoteOn()
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
 