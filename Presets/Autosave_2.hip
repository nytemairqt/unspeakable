Processor 
Type SynthChain ID Unspeakable Bypassed Gain 	      �?Balance 	        VoiceLimit 	      P@KillFadeTime 	      4@IconColour 0 packageName  BuildVersion �  EditorStates BodyShown 0 Visible 1 Solo 0 Folded 1  ChildProcessors  Processor Type MidiProcessorChain ID Midi Processor Bypassed EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors  Processor Type ScriptProcessor ID Interface Bypassed Script <	//Content.makeFrontInterface(540, 280);
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
  EditorStates BodyShown 1 Visible 1 Solo 0 contentShown 1 onInitOpen 1  ChildProcessors   Content  Control type ScriptSlider id knbInputGain value 	         Control type ScriptSlider id knbOutputGain value 	         Control type ScriptSlider id 	knbMode value 	         Control type ScriptSlider id knbClarity value 	         Control type ScriptButton id btnEQA value 	      �? Control type ScriptButton id btnEQB value 	         Control type ScriptButton id btnEQC value 	         Control type ScriptButton id 
btnEQOff value 	         UIData  ContentProperties DeviceType 	Desktop Component type ScriptPanel id pnlBG x 	        y 	        width *  height �  locked 1  Component 	type ScriptSlider id knbInputGain x <   y 	      T@text Input Gain max 	      P@middlePosition 	      @@width 	     �b@height 	     �b@ Component 
type ScriptSlider id knbOutputGain x 	     8�@y 	     @R@text Output Gain min 	      Y�max 	        middlePosition 	      I�width 	     �b@height 	     �b@ Component 	type ScriptSlider id 	knbMode x �   y 	      d@max 	      @stepSize 	      �?text Mode width 	      X@height 	      X@ Component type ScriptSlider id knbClarity x �  y 	      d@text 	Clarity middlePosition 	      �?width 	      X@height 	      X@ Component type ScriptButton id btnEQA x G  y A  width 	      N@height 	      8@text A radioGroup 	      �? Component type ScriptButton id btnEQB x �  y A  width 	      N@height 	      8@text B radioGroup 	      �? Component type ScriptButton id btnEQC x �  y A  width 	      N@height 	      8@text C radioGroup 	      �? Component type ScriptButton id 
btnEQOff x �   y A  width <   height 	      8@text OFF radioGroup 	      �? Component type ScriptLabel id lblInputGainValue x 	      N@y 	      o@width 	     �b@text 0.00dB fontName bold fontSize 	      0@ Component 	type ScriptLabel id lblOutputGainValue x 	     8�@y 	     �o@text 0.00dB width 	     �b@fontName bold height    fontSize 	      0@ Component type ScriptLabel id lblModeValue x �   y 	     �p@text A width 	      X@fontName bold fontSize 	      0@ Component type ScriptLabel id lblClarityValue x �  y 	     �p@text 0% width 	      X@fontName bold fontSize 	      0@ Component type ScriptLabel id lblInputGain x <   y    width 	     �b@text Input Gain fontName bold fontSize 	      0@ Component type ScriptLabel id lblOutputGain x 	     8�@y 	      ;@width 	     �b@text Output Gain fontName bold fontSize 	      0@ Component type ScriptLabel id lblClarity x �  y 	     �\@text 	Clarity width 	      X@fontName bold fontSize 	      0@ Component type ScriptLabel id 	lblMode x �   y 	     �\@text Mode width 	      X@fontName bold fontSize 	      0@ Processor Type ModulatorChain ID GainModulation Bypassed Intensity 	      �?EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors   Processor Type ModulatorChain ID PitchModulation Bypassed Intensity 	        EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors   Processor Type EffectChain ID FX Bypassed EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors  Processor Type 
ScriptFX ID 
scriptFX Bypassed Script � function prepareToPlay(sampleRate, blockSize)
{
	
}
 function processBlock(channels)
{
	
}
 function onControl(number, value)
{
	
}
  EditorStates BodyShown 1 Visible 1 Solo 0  ChildProcessors   RoutingMatrix NumSourceChannels    Channel0     Send0 ����Channel1    Send1 ���� Content   Networks  Network ID UnspeakableDSP AllowCompilation 1 Version 0.0.0  UIData  ContentProperties DeviceType 	Desktop  Processor #Type 	CurveEq ID eqA Bypassed NumFilters    Band0 	    ��?Band1 	      ^@Band2 	   ���?Band3 	      �?Band4 	      @Band5 	    ���Band6 	   @)�R@Band7 	      �?Band8 	      �?Band9 	      �?Band10 	    )\�Band11 	   �N�@Band12 	    )\@Band13 	      �?Band14 	      @Band15 	   ��!��Band16 	   @��@Band17 	   �=
�?Band18 	      �?Band19 	      @Band20 	    {��Band21 	   `�i�@Band22 	   ��@Band23 	      �?Band24 	      @Band25 	    ���Band26 	   �7��@Band27 	    ף�?Band28 	      �?Band29 	      @FFTEnabled EditorStates BodyShown 1 Visible 1 Solo 0  ChildProcessors   RoutingMatrix NumSourceChannels    Channel0     Send0 ����Channel1    Send1 ���� Processor (Type 	CurveEq ID eqB Bypassed NumFilters    Band0 	   ��!��Band1 	   @�P@Band2 	      �?Band3 	      �?Band4 	      �?Band5 	   @�p�?Band6 	   �$�a@Band7 	      �?Band8 	      �?Band9 	      @Band10 	   ���Band11 	   �,�@Band12 	      �?Band13 	      �?Band14 	      @Band15 	   `
�@Band16 	   ����@Band17 	   �p�?Band18 	      �?Band19 	      @Band20 	   �23��Band21 	   ����@Band22 	   �=
@Band23 	      �?Band24 	      @Band25 	    �6@Band26 	    S��@Band27 	      �?Band28 	      �?Band29 	      @Band30 	    �/@Band31 	   �Ά�@Band32 	   �p=�?Band33 	      �?Band34 	      @FFTEnabled EditorStates BodyShown 1 Visible 1 Solo 0  ChildProcessors   RoutingMatrix NumSourceChannels    Channel0     Send0 ����Channel1    Send1 ���� Processor (Type 	CurveEq ID eqC Bypassed NumFilters    Band0 	   �=
@Band1 	     ?�@Band2 	   ����?Band3 	      �?Band4 	      @Band5 	   ��@Band6 	   @�z�@Band7 	      �?Band8 	      �?Band9 	      @Band10 	   ��z�?Band11 	   �`��@Band12 	      �?Band13 	      �?Band14 	      @Band15 	   �֣�Band16 	    lt@Band17 	      �?Band18 	      �?Band19 	      @Band20 	    {@Band21 	    u�b@Band22 	      �?Band23 	      �?Band24 	      @Band25 	    ���Band26 	   �ѓL@Band27 	      �?Band28 	      �?Band29 	      �?Band30 	    �/@Band31 	   ����@Band32 	   �z�?Band33 	      �?Band34 	      @FFTEnabled EditorStates BodyShown 1 Visible 1 Solo 0  ChildProcessors   RoutingMatrix NumSourceChannels    Channel0     Send0 ����Channel1    Send1 ���� Processor Type AudioLooper ID Audio Loop Player1 Bypassed Gain 	      �?Balance 	        VoiceLimit 	      p@KillFadeTime 	      4@IconColour 0 SyncMode 	      �?PitchTracking 	        LoopEnabled 	        RootNote 	      P@SampleStartMod 	        Reversed 	        FileName �C:\Users\nytem\Documents\Virtual Instruments & Samples\Other\Celldweller - Sonix Vol. 01\Drums\Live Loops\DRUMS-Live Beats 01 (92).wav min     max ǂ loopStart     loopEnd ǂ EditorStates BodyShown 1 Visible 1 Solo 0 Folded 1  ChildProcessors  Processor Type MidiProcessorChain ID Midi Processor Bypassed EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors   Processor Type ModulatorChain ID GainModulation Bypassed Intensity 	      �?EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors  Processor 	Type SimpleEnvelope ID DefaultEnvelope1 Bypassed Monophonic 	        Retrigger 	      �?Intensity 	      �?Attack 	      @Release 	      $@LinearMode 	      �?EditorStates BodyShown 1 Visible 1 Solo 0  ChildProcessors  Processor Type ModulatorChain ID Attack Time Modulation Bypassed Intensity 	      �?EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors   Processor Type ModulatorChain ID PitchModulation Bypassed Intensity 	        EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors   Processor Type EffectChain ID FX Bypassed EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors   RoutingMatrix NumSourceChannels    Channel0     Send0 ����Channel1    Send1 ���� Processor Type AudioLooper ID Audio Loop Player2 Bypassed Gain 	      �?Balance 	        VoiceLimit 	      p@KillFadeTime 	      4@IconColour 0 SyncMode 	      �?PitchTracking 	        LoopEnabled 	        RootNote 	      P@SampleStartMod 	        Reversed 	        FileName 'C:\Users\nytem\Desktop\vocal_take.wav min nc  max ^� loopStart nc  loopEnd ^� EditorStates BodyShown 1 Visible 1 Solo 0 Folded 1  ChildProcessors  Processor Type MidiProcessorChain ID Midi Processor Bypassed EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors   Processor Type ModulatorChain ID GainModulation Bypassed Intensity 	      �?EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors  Processor 	Type SimpleEnvelope ID DefaultEnvelope2 Bypassed Monophonic 	        Retrigger 	      �?Intensity 	      �?Attack 	      @Release 	      $@LinearMode 	      �?EditorStates BodyShown 1 Visible 1 Solo 0  ChildProcessors  Processor Type ModulatorChain ID Attack Time Modulation Bypassed Intensity 	      �?EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors   Processor Type ModulatorChain ID PitchModulation Bypassed Intensity 	        EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors   Processor Type EffectChain ID FX Bypassed EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors   RoutingMatrix NumSourceChannels    Channel0     Send0 ����Channel1    Send1 ���� Processor Type SineSynth ID Sine Wave Generator1 Bypassed Gain 	    ��?Balance 	        VoiceLimit 	      p@KillFadeTime 	      4@IconColour 0 OctaveTranspose 	        SemiTones 	        UseFreqRatio 	        CoarseFreqRatio 	      �?FineFreqRatio 	        SaturationAmount 	        EditorStates BodyShown 1 Visible 1 Solo 0 Folded 1  ChildProcessors  Processor Type MidiProcessorChain ID Midi Processor Bypassed EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors   Processor Type ModulatorChain ID GainModulation Bypassed Intensity 	      �?EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors  Processor 	Type SimpleEnvelope ID DefaultEnvelope3 Bypassed Monophonic 	        Retrigger 	      �?Intensity 	      �?Attack 	      @Release 	      $@LinearMode 	      �?EditorStates BodyShown 1 Visible 1 Solo 0  ChildProcessors  Processor Type ModulatorChain ID Attack Time Modulation Bypassed Intensity 	      �?EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors   Processor Type ModulatorChain ID PitchModulation Bypassed Intensity 	        EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors   Processor Type EffectChain ID FX Bypassed EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors  Processor Type SimpleGain ID Simple Gain1 Bypassed Gain 	    �k2@Delay 	        Width 	      Y@Balance 	        InvertPolarity 	        EditorStates BodyShown 1 Visible 1 Solo 0  ChildProcessors  Processor Type ModulatorChain ID Gain Modulation Bypassed Intensity 	      �?EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors   Processor Type ModulatorChain ID Delay Modulation Bypassed Intensity 	      �?EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors   Processor Type ModulatorChain ID Width Modulation Bypassed Intensity 	      �?EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors   Processor Type ModulatorChain ID Pan Modulation Bypassed Intensity 	      �?EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors   RoutingMatrix NumSourceChannels    Channel0     Send0 ����Channel1    Send1 ���� RoutingMatrix NumSourceChannels    Channel0     Send0 ����Channel1    Send1 ���� RoutingMatrix NumSourceChannels    Channel0     Send0 ����Channel1    Send1 ���� macro_controls  macro name 	Macro 1 value 	        midi_cc ���� macro name 	Macro 2 value 	        midi_cc ���� macro name 	Macro 3 value 	        midi_cc ���� macro name 	Macro 4 value 	        midi_cc ���� macro name 	Macro 5 value 	        midi_cc ���� macro name 	Macro 6 value 	        midi_cc ���� macro name 	Macro 7 value 	        midi_cc ���� macro name 	Macro 8 value 	        midi_cc ���� MidiAutomation   MPEData Enabled  