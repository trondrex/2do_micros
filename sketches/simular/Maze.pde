// Maze, by lmcapacho

class Maze {

  public static final int NORTH = 0x01;
  public static final int EAST  = 0x02;
  public static final int SOUTH = 0x04;
  public static final int WEST  = 0x08;
  
  private int gSize;
  private int[][] gArray;
  private int[][] gWalls;
  private int widthSquare = 60;
  private int mPosx, mPosy;

  // Constructor     
  public Maze(int size){
      
    gSize = size;
    gArray = new int[][] {{2, 0, 6, 3, 6, 7, 5, 5, 5, 3},
                          {10, 0, 10, 14, 9, 8, 6, 5, 3, 10},
                          {12, 5, 9, 10, 6, 5, 9, 2, 10, 10},
                          {6, 5, 5, 11, 10, 4, 3, 14, 9, 10},
                          {10, 4, 5, 9, 12, 5, 11, 12, 3, 10},
                          {12, 5, 5, 5, 5, 3, 10, 2, 10, 8},
                          {6, 3, 6, 5, 5, 9, 14, 9, 12, 3},
                          {10, 14, 11, 6, 5, 3, 10, 6, 5, 9},
                          {10, 10, 8, 14, 3, 12, 9, 12, 5, 3},
                          {8, 12, 5, 9, 12, 5, 5, 5, 1, 8}};
    
    gWalls = new int[][] {{13, 13, 9, 12, 9, 8, 10, 10, 10, 12},
                          {1, 6, 5, 1, 6, 7, 9, 10, 12, 5},
                          {3, 10, 6, 5, 9, 10, 6, 13, 5, 5},
                          {9, 10, 10, 4, 5, 11, 12, 1, 6, 5},
                          {5, 11, 10, 6, 3, 10, 4, 3, 12, 5},
                          {3, 10, 10, 10, 10, 12, 5, 13, 5, 7},
                          {9, 12, 9, 10, 10, 6, 1, 6, 3, 12},
                          {5, 1, 4, 9, 10, 12, 5, 9, 10, 6},
                          {5, 5, 7, 1, 12, 3, 6, 3, 10, 12},
                          {7, 3, 10, 6, 3, 10, 10, 10, 14, 7}};
    mPosx = mPosy = 0;
         
  }
  
  // Determina si hay camino al norte
  public boolean isNorth(int row, int col){
    if( (row<gSize) && (col<gSize) )
      return ( (gArray[col][row] & NORTH) == NORTH);
    else
      return false;
  }
  
  // Determina si hay camino al sur
  public boolean isSouth(int row, int col){
    if( (row<gSize) && (col<gSize) )
      return ( (gArray[col][row] & SOUTH) == SOUTH);
    else
      return false;
  }
  
  // Determina si hay camino al este
  public boolean isEast(int row, int col){
    if( (row<gSize) && (col<gSize) )
      return ( (gArray[col][row] & EAST) == EAST);
    else
      return false;
  }
  
  // Determina si hay camino al oeste
  public boolean isWest(int row, int col){
    if( (row<gSize) && (col<gSize) )
      return ( (gArray[col][row] & WEST) == WEST);
    else
      return false;
  }
  
  // Obtiene el valor de una celda
  public int getValue(int row, int col){
    if( (row<gSize) && (col<gSize) )
      return gArray[col][row];
    else
      return 0;
  }
  
  // Actualiza la posición del mouse
  public void setMouse(int row, int col){
     if( (row<gSize) && (col<gSize) ){
       mPosy = row;
       mPosx = col;
     }       
  }
  
  // Actualiza los muros de una celda
  public void setWalls(int row, int col, int walls){
     if( (row<gSize) && (col<gSize) ){
       gWalls[col][row] = walls & 0xF;
     }       
  }
  
  // Obtiene los muros de una celda
  public int getWalls(int row, int col){
      if( (row<gSize) && (col<gSize) )
       return (gWalls[col][row] & 0xF);
      else
        return 0;
  }
  
  // Actualiza el laberinto  
  public void display(){

    clear();
    background(255);
    fill(1);
    // Dibuja la línea
    for (int x = 0; x < gSize; x++) {
      for (int y = 0; y < gSize; y++) {
        stroke(1);
        strokeWeight(2);
        if( (gArray[x][y]&EAST) == 2)
          line((x*widthSquare)+50,(y*widthSquare)+50,(x*widthSquare)+widthSquare+50,(y*widthSquare)+50);
        if( (gArray[x][y]&SOUTH) == 4)
          line((x*widthSquare)+50,(y*widthSquare)+50,(x*widthSquare)+50,(y*widthSquare)+widthSquare+50);  
      }
    }
    
    // Color de línea
    stroke(204, 102, 0);
    // Ancho paredes
    strokeWeight(2);
        
    // Dibuja las paredes
    for (int x = 0; x < gSize; x++) {
      for (int y = 0; y < gSize; y++) {
        // Dibuja las paredes
        if( (gWalls[x][y]&NORTH) == NORTH) 
          line((x*widthSquare)+20, (y*widthSquare)+20, (x*widthSquare)+widthSquare+20, (y*widthSquare)+20);
        if( (gWalls[x][y]&EAST) == EAST) 
          line((x*widthSquare)+widthSquare+20, (y*widthSquare)+20, (x*widthSquare)+widthSquare+20, (y*widthSquare)+widthSquare+20);  
        if( (gWalls[x][y]&SOUTH) == SOUTH) 
          line((x*widthSquare)+20, (y*widthSquare)+widthSquare+20, (x*widthSquare)+widthSquare+20, (y*widthSquare)+widthSquare+20);
        if( (gWalls[x][y]&WEST) == WEST)
          line((x*widthSquare)+20, (y*widthSquare)+20, (x*widthSquare)+20, (y*widthSquare)+widthSquare+20);
      }
    }
    
    stroke(1);
    // Dibuja el mouse
    ellipse( (mPosx*widthSquare)+widthSquare/2+20, (mPosy*widthSquare)+widthSquare/2+20, widthSquare-20, widthSquare-20);
  }
  
}