// set initial state
// byte board[8] = {0,0,0,0,0,0,0,0};
int x = 4;
int y = 3;

// move functions

void move(int direction) {
  switch (direction) {
    case 1:
      y++;
    case 2:
      y--;
    case 3:
      x++;
    case 4:
      x--;
    default:
      return;
  
  sendByte(x+1, 1 << y);

  // keep moving around board (off the edge)
  // column = column % 8;
  
  // clear current column
  
  // add to next column

  // column++
  }
}

// set led move

// on button press: 
  // bitmask = intersection of current row and current column

  // travel_direction = button direction 

// update state until button press, then change led move direction