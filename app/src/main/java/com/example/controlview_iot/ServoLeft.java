package com.example.controlview_iot;

import android.os.AsyncTask;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;

public class ServoLeft extends AsyncTask<Void, Void, String> {
    @Override
    protected String doInBackground(Void... voids) {
        try {
            URL url = new URL("http://192.168.1.33/servoLeftON");
            HttpURLConnection httpURLConnection = (HttpURLConnection) url.openConnection();
            InputStream inputStream = httpURLConnection.getInputStream();
             if (httpURLConnection.getResponseCode() != HttpURLConnection.HTTP_OK){
                Log.d("servo left class" , "error in httpUrlConnection")
             }
            BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(inputStream));
            

        } catch (MalformedURLException e) {

        } catch (IOException e) {
            e.printStackTrace();
        }
        return null;
    }

    @Override
    protected void onPostExecute(String aVoid) {
        super.onPostExecute(aVoid);

    }
}
