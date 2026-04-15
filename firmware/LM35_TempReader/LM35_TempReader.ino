int adcValue;
float nhietDo;

void setup() {
  Serial.begin(9600);
  delay(100);
}

void loop() {
    // Đọc giá trị từ 3 cảm biến
    int rawA0 = analogRead(A0);
    int rawA1 = analogRead(A1);
    int rawA2 = analogRead(A2);

    // Tính toán nhiệt độ (LM35: 10mV/độ C)
    float t1 = (rawA0 * 500.0) / 1023.0;
    float t2 = (rawA1 * 500.0) / 1023.0;
    float t3 = (rawA2 * 500.0) / 1023.0;

    // Tạo chuỗi ký tự để chứa dữ liệu
    char buffer[50];

    // Sử dụng sprintf để định dạng chuỗi: "T1:xx, T2:xx, T3:xx"
    // Lưu ý: Arduino mặc định không hỗ trợ %f cho sprintf, 
    // nên ta ép kiểu về int hoặc dùng dtostrf nếu muốn lấy số thập phân.
    sprintf(buffer, "Temp1:%d C, Temp2:%d C, Temp3:%d C", (int)t1, (int)t2, (int)t3);

    // Gửi toàn bộ chuỗi lên Serial Monitor một lần duy nhất
    Serial.println(buffer);

    delay(1000);
}
//code đuoc cap nhat boi le van hoang 
