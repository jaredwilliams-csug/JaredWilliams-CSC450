
public class Counter implements Runnable {
    private int val;
    private int endVal;
    private int finalInt;
    private final Operation operation;

    /**
     * Constructor for Counter class
     * Defaults beginningInt and endingInt to 0
     * @param operation Enum value indication incrementing or decrementing
     */
    public Counter(Operation operation) {
        this(operation, 0, 0);
    }

    /**
     * Constructor for Counter clas
     * @param beginningInt int to count from
     * @param endingInt int to count to
     * @param operation Enum value indication incrementing or decrementing
     */
    public Counter(Operation operation, int beginningInt, int endingInt) {
        this.val = beginningInt;
        this.endVal = endingInt;
        this.operation = operation;
    }

    @Override
    public void run() {
        System.out.println(Thread.currentThread()
                .getName() + ": " + val);
        Count();
    }

    /**
     * Set the value to count to
     * @param endingInt int value to count to
     */
    public void SetEndVal(int endingInt) {
        this.endVal = endingInt;
    }

    /**
     * Sets the value to count from
     * @param beginningInt int value to count from
     */
    public void SetVal (int beginningInt) {
        this.val = beginningInt;
    }

    /**
     * Gets the final value after the thread run() finishes.
     * When called before run(), it will always return 0.
     * @return int
     */
    public int GetFinalInt() {
        return finalInt;
    }

    private void Count() {
        if(val == endVal){
            throw new IllegalArgumentException("Initial and ending integers can not be the same value.");
        }
        finalInt = this.operation == Operation.Increment ? increment(val,endVal) : decrement(val,endVal);
    }

    private int increment(int val, int max) {
        if(max < val) {
            throw new IllegalArgumentException("You can't count up to a lower number.");
        }
        int value = val;
        while (value < max) {
            value++;
            System.out.println(Thread.currentThread()
                    .getName() + ": " + value);
        }
        return value;
    }
    private int decrement(int val, int min) {
        if(min > val) {
            throw new IllegalArgumentException("You can not count down to a higher number.");
        }
        int value = val;
        while (value > min) {
            value--;
            System.out.println(Thread.currentThread()
                    .getName() + ": " + value);
        }
        return value;
    }

    /**
     * An enumeration to specify counting direction
     */
    public enum Operation {
        Increment,
        Decrement
    }
}
