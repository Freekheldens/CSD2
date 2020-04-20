// ellipse 2 (purple)
let x2;
let y2;
let s2;

// ellipse 3 (red)
let x3;
let y3;
let s3;

let clicks;
let score;
let high_score;
let timing;

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
  frameRate(60);
  background(40);

  fill(250);
  noStroke();
  ellipse(windowWidth/2, 0, 60, 60);

  fill(100, 50, 200);
  noStroke();
  ellipse(x2, y2, s2, s2);

  fill(150, 0, 50);
  noStroke();
  ellipse(x3, y3, s3, s3);

  textSize(19);
  fill(0);
  text('Reset', windowWidth/2-25, 16);
  fill(255);
  text('Score:', 7, 16);
  fill(0, 255, 0);
  textSize(18);
  text(score, 63, 17);
  fill(255);
  text('Highscore:', windowWidth-150, 16);
  fill(0, 255, 0);
  textSize(18);
  text(high_score, windowWidth-62, 17);

  // moving ellipses down
  y2 += clicks/100;
  y3 += clicks/100;

  // playing metronome
  timing++;
  if (timing % 40 == 0){
    metronome.play();
  }

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

  // check if the mouse is inside the red ellipse and reposition ellipse if so
  if (
    mouseX >= x3 - s3/2 &&
    mouseX <= x3 + s3/2 &&
    mouseY >= y3 - s3/2 &&
    mouseY <= y3 + s3/2 &&
    mouseIsPressed
  ) {
    x3 = random(s3, windowWidth - s3);
    y3 = random(s3, windowHeight - s3);
    s3 = random(50, 120);
  }

  // score count and fall speed of balls
  if (mouseIsPressed){
    clicks += 1;
    score += 1;
  }

  if (score > high_score){
    high_score = score
  };

  // 2 ways for game to end
  if (
    y2 > windowHeight + s2
  ) {
    reset();
  }

  if (
    y3 > windowHeight + s3
  ) {
    reset();
  }

} // end of draw loop

// function for playing the sounds when pressed on an ellipse
function mousePressed() {
  // red ellipse
  if (
    mouseX >= x3 - s3/2 &&
    mouseX <= x3 + s3/2 &&
    mouseY >= y3 - s3/2 &&
    mouseY <= y3 + s3/2 &&
    mouseIsPressed
  ) {
    kick.play();
  }

  // purple ellipse
  if (
    mouseX >= x2 - s2/2 &&
    mouseX <= x2 + s2/2 &&
    mouseY >= y2 - s2/2 &&
    mouseY <= y2 + s2/2 &&
    mouseIsPressed
  ) {
    snare.play();
  }
}

function reset(){
  x2 = random(60, windowWidth-60);
  y2 = random(60, windowHeight-60);
  s2 = 70;

  x3 = random(60, windowWidth-60);
  y3 = random(60, windowHeight-60);
  s3 = 50;

  clicks = 0;
  score = 0;
  timing = 0;
}
