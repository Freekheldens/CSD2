let x1;
let y1;
let s1;

let x2;
let y2;
let s2;

let x3;
let y3;
let s3;

let x4;
let y4;
let s4;

function setup() {
  createCanvas(windowWidth, windowHeight);

  x1 = random(60, windowWidth-60);
  y1 = random(60, windowHeight-60);
  s1 = 60;

  x2 = random(60, windowWidth-60);
  y2 = random(60, windowHeight-60);
  s2 = 60;

  x3 = random(60, windowWidth-60);
  y3 = random(60, windowHeight-60);
  s3 = 60;

  x4 = random(60, windowWidth-60);
  y4 = random(60, windowHeight-60);
  s4 = 60;
}

function draw() {
  background(204, 120);

  fill(250);
  noStroke();
  ellipse(windowWidth/2, 0, 60, 60);

  fill(50);
  noStroke();
  ellipse(x1, y1, s1, s1);

  fill(100);
  noStroke();
  ellipse(x2, y2, s2, s2);

  fill(150);
  noStroke();
  ellipse(x3, y3, s3, s3);

  fill(170);
  noStroke();
  ellipse(x4, y4, s4, s4);

  // reset button
  if (
    mouseX >= windowWidth/2 - 30 &&
    mouseX <= windowWidth/2 + 30 &&
    mouseY >= 0 - 30 &&
    mouseY <= 0 + 30 &&
    mouseIsPressed
  ) {
    x1 = random(60, windowWidth-60);
    y1 = random(60, windowHeight-60);
    s1 = 60;

    x2 = random(60, windowWidth-60);
    y2 = random(60, windowHeight-60);
    s2 = 60;

    x3 = random(60, windowWidth-60);
    y3 = random(60, windowHeight-60);
    s3 = 60;
  }

  // check if the mouse is inside the ellipse and tickle if so
  if (
    mouseX >= x1 - abs(s1/2) &&
    mouseX <= x1 + abs(s1/2) &&
    mouseY >= y1 - abs(s1/2) &&
    mouseY <= y1 + abs(s1/2) &&
    mouseIsPressed
  ) {
    x1 += random(-5, 5);
    y1 += random(-5, 5);
    s1 += random(-2, 2);
  }

  // check if the mouse is inside the ellipse and reposition ellipse if so
  if (
    mouseX >= x2 - s2/2 &&
    mouseX <= x2 + s2/2 &&
    mouseY >= y2 - s2/2 &&
    mouseY <= y2 + s2/2 &&
    mouseIsPressed
  ) {
    x2 = random(s2, windowWidth - s2);
    y2 = random(s2, windowHeight - s2);
  }

  // check if the mouse is inside the ellipse and reposition ellipse if so
  if (
    mouseX >= x3 - s3/2 &&
    mouseX <= x3 + s3/2 &&
    mouseY >= y3 - s3/2 &&
    mouseY <= y3 + s3/2 &&
    mouseIsPressed
  ) {
    x3 = random(s3, windowWidth - s3);
    y3 = random(s3, windowHeight - s3);
  }

  // check if the mouse is inside the ellipse and reposition ellipse if so
  if (
    mouseX >= x4 - s4/2 &&
    mouseX <= x4 + s4/2 &&
    mouseY >= y4 - s4/2 &&
    mouseY <= y4 + s4/2 &&
    mouseIsPressed
  ) {
    x4 = random(s4, windowWidth - s4);
    y4 = random(s4, windowHeight - s4);
  }

}
