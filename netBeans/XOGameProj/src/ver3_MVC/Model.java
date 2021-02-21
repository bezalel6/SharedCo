package ver3_MVC;

import java.util.ArrayList;
import java.util.Random;

/**
 * Model - XO Game Logic
 * 26/1/2021
 * By Ilan Peretz (ilanperets@gmail.com).
 */
public class Model 
{
    // Constants - קבועים
    public static final char X_SIGN = 'X';
    public static final char O_SIGN = 'O';
    public static final char EMPTY_SIGN = ' ';
    private static int ROWS;  // מספר השורות במטריצה
    private static int COLS;  // מספר העמודות במטריצה

    // תכונות
    private char[][] logicBoard;   // לוח משחק לוגי
    
    /**
     * 
     * @param boardSize 
     */
    public Model(int boardSize)
    {
        ROWS = boardSize;
        COLS = boardSize;
        
        // יצירת לוח לוגי לצורך בדיקות וקבלת החלטות במשחק
        logicBoard = new char[ROWS][COLS];
    }
    
    // פעולה לאתחול לוגי של משחק חדש
    public void setup()
    {
        for (int row= 0; row < ROWS; row++)        
        {
            for (int col= 0; col < COLS; col++)            
            {
                logicBoard[row][col] = EMPTY_SIGN;
            }
        }
    }
    public ArrayList<Location> freeSpots()
    {
        // רשימת מיקומי 
        ArrayList<Location> found = new ArrayList();

        // נבדוק האם יש ניצחון לשחקן הנוכחי באחת מהשורות
        for (int row = 0; row < ROWS; row++)
        {
            for (int col = 0; col < COLS; col++)
            {
                if (logicBoard[row][col] == EMPTY_SIGN)
                {
                    found.add(new Location(row,col));
                }
            }
        }
        return found;
    }
    // controller 
    public void makeMove(Location loc, char playerSign)
    {
        if(playerSign == 'X')
            logicBoard[loc.getRow()][loc.getCol()] = X_SIGN;
        else
            logicBoard[loc.getRow()][loc.getCol()] = O_SIGN;
    }

    // פעולה לבדיקת ניצחון עבור שחקן מסוים
    // הפעולה מקבלת סימן של שחקן ובודקת האם יש לו ניצחון
    // אם יש לשחקן ניצחון הפעולה מחזירה מערך דינמי של מיקומים
    // nullאם אין לשחקן ניצחון הפעולה מחזירה 
    public ArrayList<Location> checkWin(char playerSign)
    {
        // רשימת מיקומי 
        ArrayList<Location> winLocList = new ArrayList();

        // נבדוק האם יש ניצחון לשחקן הנוכחי באחת מהשורות
        for (int row = 0; row < ROWS; row++)
        {
            winLocList.clear();
            for (int col = 0; col < COLS; col++)
            {
                if (logicBoard[row][col] != playerSign)
                {
                    break;
                } else
                {
                    winLocList.add(new Location(row, col));
                }
            }
            if (winLocList.size() == ROWS)
            {
                return winLocList;
            }
        }

        // נבדוק האם יש ניצחון לשחקן הנוכחי באחת מהעמודות
        for (int col = 0; col < COLS; col++)
        {
            winLocList.clear();
            for (int row = 0; row < ROWS; row++)
            {
                if (logicBoard[row][col] != playerSign)
                {
                    break;
                } else
                {
                    winLocList.add(new Location(row, col));
                }
            }
            if (winLocList.size() == COLS)
            {
                return winLocList;
            }
        }

        // נבדוק האם יש ניצחון לשחקן הנוכחי באלכסון הראשי
        winLocList.clear();
        for (int i = 0; i < ROWS; i++)
        {
            if (logicBoard[i][i] != playerSign)
            {
                break;
            } else
            {
                winLocList.add(new Location(i, i));
            }
        }
        if (winLocList.size() == ROWS)
        {
            return winLocList;
        }

        // נבדוק האם יש ניצחון לשחקן הנוכחי באלכסון משני
        winLocList.clear();
        for (int i = 0; i < ROWS; i++)
        {
            if (logicBoard[i][ROWS - i - 1] != playerSign)
            {
                break;
            } else
            {
                winLocList.add(new Location(i, ROWS - i - 1));
            }
        }
        if (winLocList.size() == ROWS)
        {
            return winLocList;
        }

        // אם הגענו לכאן לא נמצא ניצחון בלוח
        return null;
    }

    // פעולה שבודקת האם המשחק נגמר בתיקו
    // true אם כן הפעולה מחזירה
    // false אם לא הפעולה מחזירה
    public boolean checkTie()
    {
        for (int row = 0; row < ROWS; row++)
        {
            for (int col = 0; col < COLS; col++)
            {
                // אם יש כפתור פנוי אז אין תיקו
                if (logicBoard[row][col] == EMPTY_SIGN)
                {
                    return false;
                }
            }
        }

        // אם היגענו לכאן זה אומר שיש תיקו
        return true;
    }
    
    @Override
    public String toString()
    {
        String str="";
        for (int row= 0; row < ROWS; row++)        
        {
            for (int col= 0; col < COLS; col++)            
            {
                if(logicBoard[row][col] == EMPTY_SIGN)
                    str += "-";
                else
                    str += logicBoard[row][col]+"";
            }
            str += "\n";
        }
        return str;
    }

    public Location getAiMove() {
        Random rand = new Random();
        // צריך לבקש מהמודל מהלך ממוחשב אקראי או ראשון פנוי או בינה מלאכותית
        ArrayList<Location> empty = freeSpots();
        return empty.get(rand.nextInt(empty.size()));
    }
}
