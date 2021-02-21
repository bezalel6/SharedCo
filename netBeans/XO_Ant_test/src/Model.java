import java.util.ArrayList;

public class Model {

    private char[][] charMat;  // מטריצת הכפתורים
    private char player;         // סימן השחקן שתורו לשחק כעת
    private int ROWS;
    private int COLS;

    public Model(int ROWS, int COLS) {
        this.ROWS = ROWS;
        this.COLS = COLS;
        charMat = new char[ROWS][COLS];
    }

    public char getPlayer() {
        return player;
    }

    public void initGame() {
        player = 'X';

    }

    // בעת לחיצה על כפתור תזומן פעולה זו
    public char buttonClicked(Location loc) {
        charMat[loc.getRow()][loc.getCol()] = player;

        //? האם המשחק נגמר
        char check = checkGameStatus();
        if (check == ' ') // החלפת סימן שחקן תור מתחלף
        {
            changeTurn();
        }
        return check;
    }

    public void cleanBoard() {
        for (int row = 0; row < ROWS; row++) {
            for (int col = 0; col < COLS; col++) {
                charMat[row][col] = ' ';
            }
        }
        // 3. שחקן מתחיל והודעה
        initGame();
    }

    private ArrayList<Location> winLocList = new ArrayList();

    // בדיקת ניצחון
    public ArrayList<Location> checkWin(char player) {
        // רשימת מיקומי

        // נבדוק האם יש ניצחון לשחקן הנוכחי באחת מהשורות
        for (int row = 0; row < ROWS; row++) {
            winLocList.clear();
            for (int col = 0; col < COLS; col++) {
                if (charMat[row][col] != player) {
                    break;
                } else {
                    winLocList.add(new Location(row, col));
                }
            }
            if (winLocList.size() == ROWS) {
                return winLocList;
            }
        }

        // נבדוק האם יש ניצחון לשחקן הנוכחי באחת מהעמודות
        for (int col = 0; col < COLS; col++) {
            winLocList.clear();
            for (int row = 0; row < ROWS; row++) {
                if (charMat[row][col] != player) {
                    break;
                } else {
                    winLocList.add(new Location(row, col));
                }
            }
            if (winLocList.size() == COLS) {
                return winLocList;
            }
        }

        // נבדוק האם יש ניצחון לשחקן הנוכחי באלכסון הראשי
        winLocList.clear();
        for (int i = 0; i < ROWS; i++) {
            if (charMat[i][i] != player) {
                break;
            } else {
                winLocList.add(new Location(i, i));
            }
        }
        if (winLocList.size() == ROWS) {
            return winLocList;
        }

        // נבדוק האם יש ניצחון לשחקן הנוכחי באלכסון משני
        winLocList.clear();
        for (int i = 0; i < ROWS; i++) {
            if (charMat[i][ROWS - i - 1] != player) {
                break;
            } else {
                winLocList.add(new Location(i, ROWS - i - 1));
            }
        }
        if (winLocList.size() == ROWS) {
            return winLocList;
        }

        // אם הגענו לכאן לא נמצא ניצחון בלוח
        return null;
    }

    /*
    הפונקצייה מחזירה את רשימת המיקומים המנצחי
     */
    ArrayList<Location> getWinLocs() {
        return winLocList;
    }

    /**
     * הפעולה בודקת האם המשחק ניגמר
     *
     * @return 'X' if x won, or 'O' if player o won, or 'T' if Tie, or ' ' game
     * not over
     */
    public char checkGameStatus() {
        System.out.print(">> checkGameStatus: ");

        //1. נבדוק האם יש ניצחון לשחקן הנוכחי זה ששיחק כעת
        // =============================================
        ArrayList<Location> winLocs = checkWin(player);
        if (winLocs != null) {
            System.out.println(player + " WIN! " + winLocs);
            return player;
        }

        //2. נבדוק האם יש תיקו כלומר נגמר המשחק ואף אחד לא ניצח
        // ====================================================
        boolean isTie = true;
        for (int row = 0; row < ROWS; row++) {
            for (int col = 0; col < COLS; col++) {
                if (charMat[row][col] == ' ') {
                    isTie = false;
                }
            }
        }
        if (isTie) {
            System.out.println("TIE - No Winners!");
            return 'T';
        }
        //3. אין ניצחון ואין תיקו המשחק ממשיך
        // ====================================================
        System.out.println("continue to play...");
        return ' ';
    }

    public void changeTurn() {
        if (player == 'X') {
            player = 'O';
        } else {
            player = 'X';
        }
    }

}
