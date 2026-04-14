// 1. Khai báo lại kích thước mảng thành 3 phần tử
int adcValues[3]; 
float nhietDo[3]; 
char chuoi[50]; // Tăng kích thước chuỗi buffer

void loop() {
    // 2. Đọc thêm kênh A2
    adcValues[0] = analogRead(A0);
    adcValues[1] = analogRead(A1);
    adcValues[2] = analogRead(A2); // Kênh mới thêm

    // 3. Tính toán nhiệt độ cho cả 3 kênh
    for(int i = 0; i < 3; i++) {
        nhietDo[i] = (adcValues[i] * 500.0) / 1023.0;
    }

    // 4. Đóng gói dữ liệu gửi lên PC (định dạng CSV: kênh0,kênh1,kênh2)
    sprintf(chuoi, "%d,%d,%d\n", (int)nhietDo[0], (int)nhietDo[1], (int)nhietDo[2]);
    Serial.print(chuoi);
    
    delay(1000);
}
