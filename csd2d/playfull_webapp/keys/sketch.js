// ellipse 1 (purple)
let x1;
let y1;
let s1;

// ellipse 2 (red)
let x2;
let y2;
let s2;

// ellipse 3
let x3;
let y3;
let s3;

// ellipse 4
let x4;
let y4;
let s4;

// ellipse 5
let x5;
let y5;
let s5;

// ellipse 6
let x6;
let y6;
let s6;

// sound files
let c;
let ds;
let f;
let fs;
let g;
let as;

function preload() {
  c = loadSound('c.mp3')
  ds = loadSound('ds.mp3')
  f = loadSound('f.mp3')
  fs = loadSound('fs.mp3')
  g = loadSound('g.mp3')
  as = loadSound('as.mp3')
}


function setup() {
  createCanvas(windowWidth, windowHeight);
  reset();
}

function draw() {
  background(40);

  fill(100, 50, 200);
  noStroke();
  ellipse(x1, y1, s1, s1);

  fill(150, 0, 50);
  noStroke();
  ellipse(x2, y2, s2, s2);

  fill(0, 0, 50);
  noStroke();
  ellipse(x3, y3, s3, s3);

  fill(20, 100, 50);
  noStroke();
  ellipse(x4, y4, s4, s4);

  fill(100, 50, 80);
  noStroke();
  ellipse(x5, y5, s5, s5);

  fill(10, 150, 150);
  noStroke();
  ellipse(x6, y6, s6, s6);

  // moving ellipses down
  y1 += 2;
  y2 += 3;
  y3 += 3;
  y4 += 3;
  y5 += 2;
  y6 += 3;

  // check if the mouse is inside ellipse 1 and reposition ellipse if so
  if (
    mouseX >= x1 - s1/2 &&
    mouseX <= x1 + s1/2 &&
    mouseY >= y1 - s1/2 &&
    mouseY <= y1 + s1/2 &&
    mouseIsPressed
  ) {
    x1 = random(s1, windowWidth - s1);
    y1 = random(s1, windowHeight - s1);
    s1 = random(50, 80);
  }

  // check if the mouse is inside ellipse 2 and reposition ellipse if so
  if (
    mouseX >= x2 - s2/2 &&
    mouseX <= x2 + s2/2 &&
    mouseY >= y2 - s2/2 &&
    mouseY <= y2 + s2/2 &&
    mouseIsPressed
  ) {
    x2 = random(s2, windowWidth - s2);
    y2 = random(s2, windowHeight - s2);
    s2 = random(50, 80);
  }

  // check if the mouse is inside ellipse 3 and reposition ellipse if so
  if (
    mouseX >= x3 - s3/2 &&
    mouseX <= x3 + s3/2 &&
    mouseY >= y3 - s3/2 &&
    mouseY <= y3 + s3/2 &&
    mouseIsPressed
  ) {
    x3 = random(s3, windowWidth - s3);
    y3= random(s3, windowHeight - s3);
    s3 = random(50, 80);
  }

  // check if the mouse is inside ellipse 4 and reposition ellipse if so
  if (
    mouseX >= x4 - s4/2 &&
    mouseX <= x4 + s4/2 &&
    mouseY >= y4 - s4/2 &&
    mouseY <= y4 + s4/2 &&
    mouseIsPressed
  ) {
    x4 = random(s4, windowWidth - s4);
    y4= random(s4, windowHeight - s4);
    s4 = random(50, 80);
  }

  // check if the mouse is inside ellipse 5 and reposition ellipse if so
  if (
    mouseX >= x5 - s5/2 &&
    mouseX <= x5 + s5/2 &&
    mouseY >= y5 - s5/2 &&
    mouseY <= y5 + s5/2 &&
    mouseIsPressed
  ) {
    x5 = random(s5, windowWidth - s5);
    y5= random(s5, windowHeight - s5);
    s5 = random(50, 80);
  }

  // check if the mouse is inside ellipse 6 and reposition ellipse if so
  if (
    mouseX >= x6 - s6/2 &&
    mouseX <= x6 + s6/2 &&
    mouseY >= y6 - s6/2 &&
    mouseY <= y6 + s6/2 &&
    mouseIsPressed
  ) {
    x6 = random(s6, windowWidth - s6);
    y6= random(s6, windowHeight - s6);
    s6 = random(50, 80);
  }

  // making ellipses fall from top of screen
  if (y1 > windowHeight + s1){
    x1 = random(0 + s1, windowWidth -s1);
    y1 = 0 - s1;
  }

  if (y2 > windowHeight + s2){
    x2 = random(0 + s2, windowWidth -s2);
    y2 = 0 - s2;
  }

  if (y3 > windowHeight + s3){
    x3 = random(0 + s3, windowWidth -s3);
    y3 = 0 - s3;
  }

  if (y4 > windowHeight + s4){
    x4 = random(0 + s4, windowWidth -s4);
    y4 = 0 - s4;
  }

  if (y5 > windowHeight + s5){
    x5 = random(0 + s5, windowWidth -s5);
    y5 = 0 - s5;
  }

  if (y6 > windowHeight + s2){
    x6 = random(0 + s6, windowWidth -s6);
    y6 = 0 - s6;
  }

} // end of draw loop

// function for playing the sounds when pressed on an ellipse and for playing metronome
function mousePressed() {

  // ellipse 1
  if (
    mouseX >= x1 - s1/2 &&
    mouseX <= x1 + s1/2 &&
    mouseY >= y1 - s1/2 &&
    mouseY <= y1 + s1/2 &&
    mouseIsPressed
  ) {
    c.play();
  }

  // ellipse 2
  if (
    mouseX >= x2 - s2/2 &&
    mouseX <= x2 + s2/2 &&
    mouseY >= y2 - s2/2 &&
    mouseY <= y2 + s2/2 &&
    mouseIsPressed
  ) {
    ds.play();
  }

  // ellipse 3
  if (
    mouseX >= x3 - s3/2 &&
    mouseX <= x3 + s3/2 &&
    mouseY >= y3 - s3/2 &&
    mouseY <= y3 + s3/2 &&
    mouseIsPressed
  ) {
    f.play();
  }

  // ellipse 4
  if (
    mouseX >= x4 - s4/2 &&
    mouseX <= x4 + s4/2 &&
    mouseY >= y4 - s4/2 &&
    mouseY <= y4 + s4/2 &&
    mouseIsPressed
  ) {
    fs.play();
  }

  // ellipse 5
  if (
    mouseX >= x5 - s5/2 &&
    mouseX <= x5 + s5/2 &&
    mouseY >= y5 - s5/2 &&
    mouseY <= y5 + s5/2 &&
    mouseIsPressed
  ) {
    g.play();
  }

  // ellipse 6
  if (
    mouseX >= x6 - s6/2 &&
    mouseX <= x6 + s6/2 &&
    mouseY >= y6 - s6/2 &&
    mouseY <= y6 + s6/2 &&
    mouseIsPressed
  ) {
    as.play();
  }
}

function reset(){
  s1 = 70;
  x1 = random(60, windowWidth-s1);
  y1 = random(60, windowHeight-s1);

  s2 = 50;
  x2 = random(60, windowWidth-s2);
  y2 = random(60, windowHeight-s2);

  s3 = 60;
  x3 = random(60, windowWidth-s3);
  y3 = random(60, windowHeight-s3);

  s4 = 55;
  x4 = random(60, windowWidth-s4);
  y4 = random(60, windowHeight-s4);

  s5 = 65;
  x5 = random(60, windowWidth-s5);
  y5 = random(60, windowHeight-s5);

  s6 = 80;
  x6 = random(60, windowWidth-s6);
  y6 = random(60, windowHeight-s6);
}
