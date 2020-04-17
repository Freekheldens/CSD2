// ellipse 1 (blue)
let x1;
let y1;
let s1;

// ellipse 2 (purple)
let x2;
let y2;
let s2;

// ellipse 3 (red)
let x3;
let y3;
let s3;

// ellipse 4 (orange)
let x4;
let y4;
let s4;

let clicks;
let score;
let timing;

// sound files
let kick;
let snare;
let cow_bell;
let metronome;

function preload() {
  kick = loadSound('kick.mp3')
  snare = loadSound('snare.mp3')
  cow_bell = loadSound('cow_bell.mp3')
  metronome = loadSound('metronome.mp3')
}


function setup() {
  createCanvas(windowWidth, windowHeight);
  reset();
}

function draw() {
  frameRate(60);
  background(40);

  fill(250);
  noStroke();
  ellipse(windowWidth/2, 0, 60, 60);

  fill(100, 100, 100);
  noStroke();
  ellipse(x1, y1, s1, s1);

  fill(100, 50, 200);
  noStroke();
  ellipse(x2, y2, s2, s2);

  fill(150, 0, 50);
  noStroke();
  ellipse(x3, y3, s3, s3);

  fill(170, 50, 0);
  noStroke();
  ellipse(x4, y4, s4, s4);

  textSize(19)
  fill(0)
  text('Reset', windowWidth/2-25, 16)
  fill(255);
  text('score:', 7, 16);
  fill(0, 255, 0);
  textSize(18);
  text(score, 63, 17)

  // moving ellipses down
  y2 += clicks/100;
  y3 += clicks/100;
  y4 += clicks/100;

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

  // check if the mouse is inside the blue ellipse and tickle if so
  if (
    mouseX >= x1 - abs(s1/2) &&
    mouseX <= x1 + abs(s1/2) &&
    mouseY >= y1 - abs(s1/2) &&
    mouseY <= y1 + abs(s1/2) &&
    mouseIsPressed
  ) {
    x1 += random(-5, 5);
    y1 += random(-5, 5);
    s1 += random(-3, 2);

    y2 -= 3;
    y3 -= 3;
    y4 -= 3;
    clicks = 50;
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
    s2 = random(40, 120);
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
    s3 = random(40, 120);
  }

  // check if the mouse is inside the orange ellipse and reposition ellipse if so
  if (
    mouseX >= x4 - s4/2 &&
    mouseX <= x4 + s4/2 &&
    mouseY >= y4 - s4/2 &&
    mouseY <= y4 + s4/2 &&
    mouseIsPressed
  ) {
    x4 = random(s4, windowWidth - s4);
    y4 = random(s4, windowHeight - s4);
    s4 = random(40, 120);
  }

  // score count and fall speed of balls
  if (mouseIsPressed){
    clicks += 1;
    score += 1;
  }

  // 3 ways for game to end
  if (
    y2 > windowHeight + s2 &&
    y4 > windowHeight + s4
  ) {
    reset();
  }

  if (
    y3 > windowHeight + s3 &&
    y4 > windowHeight + s4
  ) {
    reset();
  }

  if (
    y2 > windowHeight + s2 &&
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

  // orange ellipse
  if (
    mouseX >= x4 - s4/2 &&
    mouseX <= x4 + s4/2 &&
    mouseY >= y4 - s4/2 &&
    mouseY <= y4 + s4/2 &&
    mouseIsPressed
  ) {
    cow_bell.play();
  }
}

function reset(){
  x1 = random(60, windowWidth-60);
  y1 = random(60, windowHeight-60);
  s1 = 60;

  x2 = random(60, windowWidth-60);
  y2 = random(60, windowHeight-60);
  s2 = 70;

  x3 = random(60, windowWidth-60);
  y3 = random(60, windowHeight-60);
  s3 = 50;

  x4 = random(60, windowWidth-60);
  y4 = random(60, windowHeight-60);
  s4 = 40;

  clicks = 0;
  score = 0;
  timing = 0;
}
