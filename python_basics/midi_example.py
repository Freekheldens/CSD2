from midiutil import MIDIFile

degrees  = kick_list # MIDI note number
track    = 0
channel  = 9
timer    = 0   # In beats
tempo    = BPM  # In BPM
volume   = 100 # 0-127, as per the MIDI standard

MyMIDI = MIDIFile(1) # One track, defaults to format 1 (tempo track automatically created)
MyMIDI.addTempo(track, timer, tempo)

for volume in degrees:
    MyMIDI.addNote(track, channel, 36, timer, 0.25, volume)
    timer = timer + 0.25

degrees = clap_list
timer = 0
for volume in degrees:
    MyMIDI.addNote(track, channel, 38, timer, 0.25, volume)
    timer = timer + 0.25

degrees = hihat_list
timer = 0
for volume in degrees:
    MyMIDI.addNote(track, channel, 42, timer, 0.25, volume)
    timer = timer + 0.25

with open("irr_beat.mid", "wb") as output_file:
    MyMIDI.writeFile(output_file)
