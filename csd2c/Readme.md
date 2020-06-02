# Concept omschrijving

Een performer heeft de mogelijkheid om op diverse manieren expressie toe te voegen aan (bestaand noten) materiaal. Hierbij kan een performer meerdere parameters inzetten, denk aan klankvariaties, toonduur en dynamiek. Wij hebben een audio-tool ontwikkeld om een extra toevoeging aan muzikale expressiviteit te geven, samenhangend met dynamiek.

Er zijn genres, zoals dance, waarbij dynamiek in kleine mate voorkomt. Toch kan je je voorstellen dat een artiest dit muzikale aspect wel zou willen overbrengen aan de luisteraar. Daarom willen wij deze dynamiek voornamelijk verklanken met Distortion. Hoe harder de performer speelt, hoe meer de distortion over de sound van het instrument of synthesizer toeneemt. Lees bij harder hier: harder volume of meer velocity. Het volume / amplitude van de audio input wordt naast input dus ook gebruikt als aansturing. Op deze wijze zal er dus wel een vorm van muzikale expressiviteit worden toegevoegd. De distortion die wordt gebruikt heeft ook 2 LFO’s (een voor het linker audio kanaal, en een voor het rechter audio kanaal) voor extra bewegelijkheid en verbreding van het geluid in stereo.

Om nog meer beweeglijkheid te geven aan de vernieuwde klank is er een flanger als effect toegevoegd aan de sound van het instrument of synthesizer. Flanger leek hier een passend effect omdat de beweeglijkheid hier sterk hoorbaar in is: namelijk de flanger frequentie en diepte.

De applicatie heeft 2 standen, de “Normal Mode” is wat meer subtiel voor meer diepte in het geluid en om het geluid wat interessanter te houden. En er is nog een “Crazy Mode”, deze modus kan het geluid echt vervormen (handig voor sound design toepassingen).

Deze applicatie kan worden gebruikt voor een live-performance of in de studio bij het opnemen.

__Must Have__

Het systeem bestaat uit audio input van een instrument (in ons geval een synthesizer), waarbij de effecten Distortion en Flanger de klank veranderen. De amplitude van de audio input is de aansturing voor de effecten.

__Should Have__

In dit systeem wordt volume/velocity als vorm van muzikale expressiviteit gebruikt als aansturing. Het zou interessant zijn om ook toonduur of spectrale variaties toe te voegen als parameter. Kalibratie van het systeem.

__Could Have__

Het systeem zou een gui kunnen hebben, zodat de performer de effecten zelf naar smaak kan verzwakken of versterken.

__Won’t Have__

Andere effecten naast distortion en Flanger. Hierbij kan je bijvoorbeeld denken aan reverb en bijbehorende parameters.

# Systeem waardes

*Flanger LFO Freq value	= Normal Mode = 0 tot 1, Crazy Mode = 20 tot 220 (Hz)
*Flanger Mod Depth	= Normal Mode = 20 tot 100, Crazy Mode = 20 tot 220 (Hz)
*Flanger Feedback	= Normal Mode = 0 tot 80, Crazy Mode = 0 tot 90
*Distortion LFO Right 	=  Normal Mode = 3 tot 8, Crazy Mode = 3 tot 20 (Hz)
*Distortion LFO Left  	=  Normal Mode = 2 tot 10, Crazy Mode = 2 tot 23	 (Hz)
*Distortion LFO Depth	=  Normal Mode = 5 tot 20, Crazy Mode = 5 tot 30
