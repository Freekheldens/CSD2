// ellipse 1
let x1;
let y1;
let s1;

// ellipse 2
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

let clicks;

function setup() {
  createCanvas(windowWidth, windowHeight);

  s1 = 75;
  x1 = random(60, windowWidth - s1);
  y1 = random(60, windowHeight - s1);

  s2 = 60;
  x2 = random(60, windowWidth - s2);
  y2 = random(60, windowHeight - s2);

  s3 = 50;
  x3 = random(60, windowWidth - s3);
  y3 = random(60, windowHeight - s3);

  s4 = 60;
  x4 = random(60, windowWidth - s4);
  y4 = random(60, windowHeight - s4);

  clicks = 10;
}

function draw() {
  background(40);

  y2 += clicks/100;
  y3 += clicks/100;
  y4 += clicks/100;

  fill(250);
  noStroke();
  ellipse(windowWidth/2, 0, 60, 60);

  fill(50, 50, 100);
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
  text('Reset', windowWidth/2-25, 15)

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

    x4 = random(60, windowWidth-60);
    y4 = random(60, windowHeight-60);
    s4 = 60;

    clicks = 10;
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

    y2 -= 1;
    y3 -= 1;
    y4 -= 1;
    clicks = 50;
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
    s2 = random(10, 240);
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
    s3 = random(10, 240);
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
    s4 = random(10, 240);
  }

  if (mouseIsPressed){
    clicks += 1;
  }

}
