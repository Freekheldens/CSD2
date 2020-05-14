// ellipse 1 (purple)
let x1;
let y1;
let s1;

// ellipse 3 (red)
let x2;
let y2;
let s2;

let clicks;
let score;
let high_score;

// sound files
let kick;
let snare;
let metronome;

function preload() {
  kick = loadSound('kick.mp3')
  snare = loadSound('snare.mp3')
  metronome = loadSound('metronome.mp3')
}


function setup() {
  createCanvas(windowWidth, windowHeight);
  reset();
  high_score = 0;
}

function draw() {
  background(40);

  fill(180);
  textSize(18);
  text('Try to play on the metronome!', windowWidth/4, windowHeight/2)

  fill(250);
  noStroke();
  ellipse(windowWidth/2, 0, 60, 60);

  fill(100, 50, 200);
  noStroke();
  ellipse(x1, y1, s1, s1);

  fill(150, 0, 50);
  noStroke();
  ellipse(x2, y2, s2, s2);

  textSize(19);
  fill(0);
  text('Reset', windowWidth/2-25, 16);

  fill(255);
  text('Score:', 7, 16);

  fill(0, 255, 0);
  textSize(18);
  text(score, 63, 17);

  fill(255);
  text('Highscore:', windowWidth-130, 16);

  fill(0, 255, 0);
  textSize(18);
  text(high_score, windowWidth-44, 17);

  // moving ellipses down
  y1 += clicks/100;
  y2 += clicks/100;

  // reset button
  if (
    mouseX >= windowWidth/2 - 30 &&
    mouseX <= windowWidth/2 + 30 &&
    mouseY >= 0 - 30 &&
    mouseY <= 0 + 30 &&
    mouseIsPressed
  ) {
    reset();
    score = -1;
  }

  // check if the mouse is inside the purple ellipse and reposition ellipse if so
  if (
    mouseX >= x1 - s1/2 &&
    mouseX <= x1 + s1/2 &&
    mouseY >= y1 - s1/2 &&
    mouseY <= y1 + s1/2 &&
    mouseIsPressed
  ) {
    x1 = random(s1, windowWidth - s1);
    y1 = random(s1, windowHeight - s1);
    s1 = random(50, 120);
  }

  // check if the mouse is inside the red ellipse and reposition ellipse if so
  if (
    mouseX >= x2 - s2/2 &&
    mouseX <= x2 + s2/2 &&
    mouseY >= y2 - s2/2 &&
    mouseY <= y2 + s2/2 &&
    mouseIsPressed
  ) {
    x2 = random(s2, windowWidth - s2);
    y2 = random(s2, windowHeight - s2);
    s2 = random(50, 120);
  }

  // score count and fall speed of balls
  if (mouseIsPressed){
    clicks += 1;
    score += 1;
  }

  // setting high score
  if (score > high_score){
    high_score = score
  };

  // 2 ways for game to end
  if (
    y1 > windowHeight + s1
  ) {
    reset();
  }

  if (
    y2 > windowHeight + s2
  ) {
    reset();
  }

} // end of draw loop

// function for playing the sounds when pressed on an ellipse and for playing metronome
function mousePressed() {
  if (metronome.isPlaying()) {
    // .isPlaying() returns a boolean
  } else {
    metronome.play();
  }
  // red ellipse
  if (
    mouseX >= x2 - s2/2 &&
    mouseX <= x2 + s2/2 &&
    mouseY >= y2 - s2/2 &&
    mouseY <= y2 + s2/2 &&
    mouseIsPressed
  ) {
    kick.play();
  }

  // purple ellipse
  if (
    mouseX >= x1 - s1/2 &&
    mouseX <= x1 + s1/2 &&
    mouseY >= y1 - s1/2 &&
    mouseY <= y1 + s1/2 &&
    mouseIsPressed
  ) {
    snare.play();
  }
}

function reset(){
  x1 = random(60, windowWidth-60);
  y1 = random(60, windowHeight-60);
  s1 = 70;

  x2 = random(60, windowWidth-60);
  y2 = random(60, windowHeight-60);
  s2 = 50;

  clicks = 0;
  score = 0;
  if (metronome.isPlaying()) {
    // .isPlaying() returns a boolean
    metronome.stop();
  }
}
