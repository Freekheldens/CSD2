var song;
var amp;

var x_draw = 350;
var y_draw = 200;

var add_ampx = 1;
var add_ampy = 1;

var amp_history = [];

function mousePressed() {
  if (song.isPlaying()) {
    song.pause();
  } else {
    song.play();
  }
}

function preload() {
  song = loadSound('Side-A.mp3');
}

function setup() {
  createCanvas(700, 400);
  frameRate(30);
  amp = new p5.Amplitude();
}

function draw() {
  background(30);
  if (song.isPlaying()) {
    var vol = amp.getLevel();
    amp_history.push(vol);
    for (var i = 0; i < amp_history.length; i++ ){
      strokeWeight(5);

      // color with fft
      // i%255
      stroke(vol * 150);
      point(x_draw += add_ampx, y_draw += add_ampy);

      if (x_draw > width) {
        add_ampx = -1;
      } else if (x_draw < 0) {
        add_ampx = 1;
      }
      if (y_draw > height) {
        add_ampy = -1;
      } else if (y_draw < 0) {
        add_ampy = 1;
      }
    }
  }
}
