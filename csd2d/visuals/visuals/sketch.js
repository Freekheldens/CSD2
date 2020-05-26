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
	fft = new p5.FFT();
	amp = new p5.Amplitude();
}

function draw() {
	background(0);

	if (audio.isPlaying()) {

		fft.analyze();
		vol = amp.getLevel();

		bass = fft.getEnergy("bass");
		mid = fft.getEnergy("mid");
		treble = fft.getEnergy("treble");

		mapBass = map(bass, 0, 255, -radius, radius);
		scaleBass = map(bass, 0, 255, 0, 0.5);

		mapMid = map(mid, 0, 255, -radius, radius);
		scaleMid = map(mid, 0, 255, 1, 1.5);

		mapTreble = map(treble, 0, 255, -radius, radius);
		scaleTreble = map(treble, 0, 255, 1, 1.5);

		mapMouseX = map(mouseX, 0, width, 1, 8);
		mapMouseY = map(mouseY, 0, height, 0, windowHeight);

		pieces = mapMouseX;
		radius = mapMouseY;

		translate(windowWidth / 2, windowHeight / 2);

		for (i = 0; i < pieces; i += 1) {

			rotate(TWO_PI / pieces);


			// bass
			push();
			strokeWeight(5);
			stroke(bass);
			scale(scaleBass);
			line(mapBass, radius / 2, radius, radius);
			line(-mapBass, -radius / 2, radius, radius);
			pop();

			// mid
			push();
			strokeWeight(1);
			stroke(mid);
			scale(scaleMid);
			line(mapMid, radius / 2, radius, radius);
			line(-mapMid, -radius / 2, radius, radius);
			pop();

			// treble
			push();
			strokeWeight(0.5)
			stroke(vol*255);
			scale(scaleTreble);
			line(mapTreble, radius / 2, radius, radius);
			line(-mapTreble, -radius / 2, radius, radius);
			pop();

		}
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
