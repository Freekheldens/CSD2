# VJ-Tool voor Techno
__Link (bedoeld voor desktop):__

https://studenthome.hku.nl/~freek.heldens/visuals/

__Concept:__

Het concept wat ik voor ogen heb is een VJ-Tool, waarbij muziek en input van een gebruiker visuals genereren.
Normaliter is een VJ (video-jockey) druk bezig met het draaien aan knopjes om voor verandering in beeld te zorgen.
Dit concept zorgt ervoor dat de VJ nog steeds input kan brengen maar dat de visuals ook veranderen op basis van audio input. Dit kan handig zijn, omdat zo de audio input voor de constante verandering in visuals zorgt en de VJ af en toe ook verandering inbrengt voor wanneer er bijvoorbeeld een build-up van een nummer te horen is.

Ik persoonlijk ga graag naar Techno feesten en maak zelf ook Techno muziek, vandaar dat ik dit concept toe spits in die richting: VJ-Tool voor Techno feesten.
Visuals bij Techno feesten zijn vaak abstract, ik zelf ben daar ook groot fan van, in deze VJ-Tool zullen de visuals die gegenereerd worden dus ook abstract zijn.

Het idee is om 3 vormen in beeld te laten zien, deze 3 vormen representeren 3 frequentie banden. Namelijk: bass, mid en treble.
Ook wil ik de kleur of helderheid laten afhangen van de intensiteit van de des betreffende frequentie band.

__Mapping onderdelen:__

Amplitude waarde van de audio input in 3 frequentie banden (bass, mid, treble)
Muis X en Y waardes omzetten in verandering van visuals
Amplitude waarde van het gehele input signaal (deze ga ik misschien gebruiken)

__Minimal viable product:__

De mapping voor de m.v.p is:
Amplitude waarde van de audio input van 3 frequentie banden koppelen aan 3 vormen (waarschijnlijk worden deze gekoppeld aan X en Y van lijnen)
Amplitude waarde van de audio input van 3 frequentie banden koppelen aan kleur of helderheid van des betreffende frequentie band
Muis X en Y waardes omzetten in verandering van visuals (waarschijnlijk zal de positie van de muis bepalen hoe “druk” het beeld is, dus hoeveel vormen of lijnen er zijn)

In een volledige versie zou ik ook nog een strobe functie willen toevoegen, dit zal inhouden dat als je de muis ingedrukt houdt, de achtergrond wit wordt als er een beat gedetecteerd wordt. Hiervoor zal er wel een goede beat detectie moeten worden ontwikkeld.

__Proof of concept:__

Ik ben begonnen met een proof of concept te maken in p5, en heb gebruik gemaakt van de audio library. In de proof of concept heb ik getest of de amplitude waarde van de 3 frequentie banden en de input van een gebruiker (coordinaten van je muis) voor interessante verandering in de vormen kon zorgen. Ik persoonlijk vind de proof of concept geslaagd, er worden interessante visuals gegenereerd en je kunt er zelf ook nog invloed op uit oefenen zodat het ook langere tijd interessant blijft.
Wat ik tijdens het ontwikkelen van de proof of concept nog heb toegevoegd is dat de lijndikte afhangt van het ingang signaal (elk van de 3 vormen heeft echter wel een andere factor van dikte).


# Reflectie

__PMI van proof of concept:__

Wat ik goed vind werken zijn de 3 vormen die samen een geheel maken, de 3 frequentie banden die voor verandering van de vormen zorgen en de muis coordinaten die voor verandering van de vormen zorgen.

Wat ik minder vind werken zijn de helderheden van de lijnen die worden aangepast op basis van de amplitude van de frequentie banden, ook vind ik de reactie tijd van de audio analyze soms iets te traag.

Wat ik interessant vind aan de proof of concept is dat je heel gemakkelijk de visuals interessant kunt houden, en je kunt reageren op veranderingen in de muziek (bij bevoordeeld een build-up in de muziek kun je je muis verplaatsen zodat de visuals “drukker” worden).

__Technologische obstakels/beperkingen:__

Als je dit echt zou willen gaan gebruiken bij feesten dan is web misschien niet de beste manier omdat het soms net wat te traag werkt, en het is namelijk heel belangrijk dat het goed in sync is met de muziek.
Ook kan de input van een gebruiker beter een soort controller zijn dan je muis coordinaten, anders ziet het publiek je muis pointer.

__Gebruikte tutorials/examples:__

https://p5js.org/examples/form-triangle-strip.html
