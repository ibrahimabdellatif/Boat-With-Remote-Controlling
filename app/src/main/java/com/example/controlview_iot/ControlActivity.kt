package com.example.controlview_iot

import android.os.Bundle
import android.widget.Button
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity

class ControlActivity : AppCompatActivity() {
    lateinit var turnOnDC: Button
    lateinit var turnOffDC: Button
    lateinit var servoRight: Button
    lateinit var servoLeft: Button

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_control)

        turnOnDC = findViewById(R.id.btn_turnon)
        turnOffDC = findViewById(R.id.btn_turnoff)
        servoRight = findViewById(R.id.btn_right)
        servoLeft = findViewById(R.id.btn_left)

        //init listener
        turnOnDC.setOnClickListener {

            //init instance of class and execute it
            var dcMotorOn = DCMotorOn()
            dcMotorOn.execute()

            Toast.makeText(applicationContext, "DC is on", Toast.LENGTH_SHORT).show()
        }
        turnOffDC.setOnClickListener {

            //init instance of class and execute it
            var dcMotorOff = DCMotorOff()
            dcMotorOff.execute()

            Toast.makeText(applicationContext, "DC is off", Toast.LENGTH_SHORT).show()

        }
        servoRight.setOnClickListener {

            //init instance of class and execute it
            var servoRight = ServoRight()
            servoRight.execute()

            Toast.makeText(applicationContext, "Servo In Right", Toast.LENGTH_SHORT).show()

        }
        servoLeft.setOnClickListener {

            //init instance of class and execute it
            var servoLeft = ServoLeft()
            servoLeft.execute()

            Toast.makeText(applicationContext, "Servo Is Left", Toast.LENGTH_SHORT).show()

        }
    }
}