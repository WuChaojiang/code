package Demo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;


public class HttpRequest {
    private int code;
    private String data;

    public HttpRequest() {
        data = "";
    }

    public boolean get(String url) {
        HttpURLConnection conn = null;
        BufferedReader in = null;
        try {
            URL realUrl = new URL(url);
            conn = (HttpURLConnection)realUrl.openConnection();
            code = conn.getResponseCode();
            if (code ==  HttpURLConnection.HTTP_OK) {
                try {
                    in = new BufferedReader(new InputStreamReader(conn.getInputStream()));
                    StringBuilder sb = new StringBuilder();
                    String line;
                    while((line = in.readLine()) != null) {
                        sb.append(line);
                    }
                    data = sb.toString();
                    return true;
                } catch (Exception e) {
                    e.printStackTrace();
                    code = conn.getResponseCode();

                    return false;
                }
            } else {
                return false;
            }
        } catch (Exception e) {

        } finally {
        }
        return false;
    }

    public String getResponseData() {
        return data;
    }

    public int getCode() {
        return code;
    }
}
























