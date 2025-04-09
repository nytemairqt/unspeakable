const pnlBG = Content.getComponent("pnlBG");

const lafSliderA = Content.createLocalLookAndFeel();
const lafSliderB = Content.createLocalLookAndFeel();
const lafSliderC = Content.createLocalLookAndFeel();
const lafSliderD = Content.createLocalLookAndFeel();
const lafButton = Content.createLocalLookAndFeel();

/* Colours & Path */
var path = Content.createPath();

Engine.loadFontAs("{PROJECT_FOLDER}fonts/Inter-Regular.ttf", "regular");
Engine.loadFontAs("{PROJECT_FOLDER}fonts/Inter-Medium.ttf", "medium");
Engine.loadFontAs("{PROJECT_FOLDER}fonts/Inter-SemiBold.ttf", "semibold");
Engine.loadFontAs("{PROJECT_FOLDER}fonts/Inter-Bold.ttf", "bold");
Engine.loadFontAs("{PROJECT_FOLDER}fonts/JosefinSans-Bold.ttf", "title");

const clrRhapsodyBlue = 0xFF1D1D21;
const clrExtradarkblue = 0xFF191933;
const clrOffWhite = 0xFFEDEDED;
const clrBggrey = 0xFF121212;    
const clrExtradarkgrey = 0xFF171717;
const clrDarkgrey = 0xFF252525;   
const clrMidgrey = 0xFF555555;
const clrGrey = 0xFF808080;        
const clrLightgrey = 0xFFD3D3D3;    
const clrWhite = 0xFFFFFFFF;
const clrLightblue = 0xFFADD8E6;
const clrBlack = 0xFF000000;  
const clrKeyPurple = 0xFFCC96FF;

inline function reduced(obj, amount)
{
    return [amount, amount, obj.area[2] - 2*amount, obj.area[3] - 2* amount];
}

lafSliderA.registerFunction("drawRotarySlider", function(g, obj)
{
	this.loadImage("{PROJECT_FOLDER}knbA.png", "knbA");
	var min = -135.0;
	var max = 135.0;
	var rotation = min + ((max - min) * obj.valueNormalized);
	g.setOpacity(1.0);
	g.rotate(Math.toRadians(rotation), [obj.area[2]/2, obj.area[3]/2]);
	g.drawImage("knbA", obj.area, 0, 0);
});

lafSliderB.registerFunction("drawRotarySlider", function(g, obj)
{
	this.loadImage("{PROJECT_FOLDER}knbB.png", "knbB");
	var min = -135.0;
	var max = 135.0;
	var rotation = min + ((max - min) * obj.valueNormalized);
	g.setOpacity(1.0);
	g.rotate(Math.toRadians(rotation), [obj.area[2]/2, obj.area[3]/2]);
	g.drawImage("knbB", obj.area, 0, 0);
});

lafSliderC.registerFunction("drawRotarySlider", function(g, obj)
{
	this.loadImage("{PROJECT_FOLDER}knbC.png", "knbC");
	var min = -135.0;
	var max = 135.0;
	var rotation = min + ((max - min) * obj.valueNormalized);
	g.setOpacity(1.0);
	g.rotate(Math.toRadians(rotation), [obj.area[2]/2, obj.area[3]/2]);
	g.drawImage("knbC", obj.area, 0, 0);
});

lafSliderD.registerFunction("drawRotarySlider", function(g, obj)
{
	this.loadImage("{PROJECT_FOLDER}knbD.png", "knbD");
	var min = -135.0;
	var max = 135.0;
	var rotation = min + ((max - min) * obj.valueNormalized);
	g.setOpacity(1.0);
	g.rotate(Math.toRadians(rotation), [obj.area[2]/2, obj.area[3]/2]);
	g.drawImage("knbD", obj.area, 0, 0);
});

lafButton.registerFunction("drawToggleButton", function(g, obj)
{
	this.loadImage("{PROJECT_FOLDER}button.png", "button");
	g.setOpacity(1.0);
	g.drawImage("button", obj.area, 0, 0);
	
	g.setColour(obj.over ? Colours.withAlpha(Colours.white, 0.04) : Colours.withAlpha(Colours.white, 0.00));
	g.fillRoundedRectangle(obj.area, 2.0);
	
	g.setColour(obj.value ? clrOffWhite : clrDarkgrey);
	g.setFont("bold", 15.0);
	g.drawAlignedText(obj.text, obj.area, "centred");
});

pnlBG.setPaintRoutine(function(g)
{
	this.loadImage("{PROJECT_FOLDER}bg.png", "backgroundImage");
	g.setOpacity(1.0);
	g.drawImage("backgroundImage", [0, 0, this.getWidth(), this.getHeight()], 0, 0);
});