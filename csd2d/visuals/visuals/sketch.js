// VJ-Tool designed for Techno music that reacts to audio input and mouse coördinates.

var pieces;
var radius;

var fft;
var amp;
var vol;

var mapMouseX;
var mapMouseY;

var audio;

var bass;
var mid;
var treble;

var mapBass;
var scaleBass;

var mapMid;
var scaleMid;

var mapTreble;
var scaleTreble;


function preload() {
	audio = loadSound("Side-A.mp3");
}

function setup() {
	createCanvas(windowWidth, windowHeight);
	// setting variables to p5 FFT analyzer & p5 amplitude analyzer
	fft = new p5.FFT();
	amp = new p5.Amplitude();
}

function draw() {

	background(0);

	if (audio.isPlaying()) {

		// starting the FFT analyzer & writing amplitude values to variable vol
		fft.analyze();
		vol = amp.getLevel();

		// retrieving amplitude values from the FFT analyzer for 3 frequency bands
		bass = fft.getEnergy("bass");
		mid = fft.getEnergy("mid");
		treble = fft.getEnergy("treble");

		// scaling FFT values to usefull values
		mapBass = map(bass, 0, 255, -radius, radius);
		scaleBass = map(bass, 0, 255, 0, 0.5);

		mapMid = map(mid, 0, 255, -radius, radius);
		scaleMid = map(mid, 0, 255, 1, 1.5);

		mapTreble = map(treble, 0, 255, -radius, radius);
		scaleTreble = map(treble, 0, 255, 1, 1.5);

		// scaling mouseX & mouseY to usefull values
		mapMouseX = map(mouseX, 0, width, 1, 8);
		mapMouseY = map(mouseY, 0, height, 0, windowHeight);

		// setting mapped mouse values to amount of lines and radius
		pieces = mapMouseX;
		radius = mapMouseY;

		translate(windowWidth / 2, windowHeight / 2);

		for (i = 0; i < pieces; i += 1) {

			// rotating lines
			rotate(TWO_PI / pieces);

			// bass
			push();
			// line thickness is dependent on audio input amplitude
			strokeWeight(vol*10);
			// line color from black to white dependent on FFT bass analysis
			stroke(bass);
			// changing size of shape dependent on FFT bass analysis
			scale(scaleBass);
			// drawing lines dependent on FFT bass analysis and mouse coördinates
			line(mapBass, radius / 2, radius, radius);
			line(-mapBass, -radius / 2, radius, radius);
			pop();

			// mid
			push();
			strokeWeight(vol*4);
			stroke(mid);
			scale(scaleMid);
			line(mapMid, radius / 2, radius, radius);
			line(-mapMid, -radius / 2, radius, radius);
			pop();

			// treble
			push();
			strokeWeight(vol*3)
			stroke(treble);
			scale(scaleTreble);
			line(mapTreble, radius / 2, radius, radius);
			line(-mapTreble, -radius / 2, radius, radius);
			pop();

		}
	} else {
		textSize(32);
		fill(255);
		text('Click to start', 100, 100);
	}
}

function mousePressed() {
  if (audio.isPlaying()) {
    audio.pause();
  } else {
    audio.play();
  }
}

function windowResized() {
	resizeCanvas(windowWidth, windowHeight);
}
