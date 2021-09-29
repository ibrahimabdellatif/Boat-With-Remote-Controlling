package com.example.controlview_iot

import android.annotation.SuppressLint
import android.content.Intent
import android.os.Bundle
import android.widget.Button
import androidx.appcompat.app.AppCompatActivity

@SuppressLint("StaticFieldLeak")
lateinit var next: Button

class WiFiActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_wifi)
        next = findViewById(R.id.btn_next)

        next.setOnClickListener { click ->
            var intent = Intent(applicationContext, ControlActivity::class.java)
            startActivity(intent)
        }
    }
}