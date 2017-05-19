package com.example.test.mynativeapplication;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    // Instance variables
    private int number = 88;
    private String message = "Hello from Java";

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.string_text);
        tv.setText(stringFromJNI());

        // Example of a call to a native method add
        TextView add_result = (TextView) findViewById(R.id.add_text);
        //add_result.setText("Result = " + Integer.toString(addFromJNI(10,15)));

        int[] numbers = {22, 33, 33};
        double[] result = sumAbdAverage(numbers);
        TextView sum_average_result = (TextView) findViewById(R.id.sum_avarage_text);
        sum_average_result.setText("Sum = " + Double.toString(result[0]) + "  Average = "+ Double.toString(result[1]));

        TextView tv_instance_var = (TextView) findViewById(R.id.tv_message);
        modifyInstanceVariable();

        tv_instance_var.setText("Number = " + number + " Message = " + message);

        nativeMethod();

        final EditText editText = (EditText)findViewById(R.id.factorial_number_input);
        Button mButton = (Button) findViewById(R.id.input_btn);

        mButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try {
                    int factorial_Number = 0;
                    factorial_Number = Integer.parseInt(editText.getText().toString());
                    Log.d("XYZ","Input factorial Number = " + factorial_Number);
                    TextView factorial_result = (TextView) findViewById(R.id.factorial_result);
                    factorial_result.setText("Result = " + getFactorial(factorial_Number));
                }catch (Exception e){

                }
            }
        });




    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
    //public native int addFromJNI(int a, int b);

    // Declare a native method sumAndAverage() that receives an int[] and
    //  return a double[2] array with [0] as sum and [1] as average
    public native double[] sumAbdAverage(int[] numbers);


    //double[] results = new TestJNIPrimitiveArray().sumAndAverage(numbers);
    //System.out.println("In Java, the sum is " + results[0]);
   // System.out.println("In Java, the average is " + results[1]);


    // Declare a native method that modifies the instance variables
    private native void modifyInstanceVariable();

    private native void staticMethod();

    // Declare a native method that calls back the Java methods below
    private native void nativeMethod();

    // To be called back by the native code
    private void callback() {
        System.out.println("In Java");
    }

    private void callback(String message) {
        System.out.println("In Java with " + message);
    }

    private double callbackAverage(int n1, int n2) {
        return ((double)n1 + n2) / 2.0;
    }

    // Static method to be called back
    private static String callbackStatic() {
        return "From static Java method";
    }

    private native void nativeArrayObjectMethod();

    private native int getFactorial(int number);
}

