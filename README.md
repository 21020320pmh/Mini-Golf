# Mini-Golf
 Dự án cuối kì
# 1.Hướng dẫn cài đặt:

 	- Clone code về máy bằng dòng lệnh: git clone https://github.com/[tên_github_cá_nhân]/Mini-Golf
 	- Mở folder code vừa được tải về bằng phần mềm
 	- New Terminal, nhập vào Terminal lệnh: mingw32-make
 	- Nhập tiếp lệnh: .\main.exe rồi Enter để chạy chương trình
# 2.Mô tả chung về trò chơi, các ý tưởng chính

  - Là game đánh golf theo level và tính số lần ít nhất để thắng game.
## Về cách chơi:

  - Sử dụng chuột để ấn vào màn hình sẽ hiện ra thanh lực và hướng để di chuyển bóng.
  - Kéo thả lực một cách hợp lí để có thể đưa bóng vào lỗ 1 cách ngắn nhất.
## Các ý tưởng chính:

  - Mỗi khi ấn chuột và kéo sẽ tạo ra vận tốc lực dựa trên tọa độ x và y của chuột, sau khi thả sẽ khiến
    cho bóng di chuyển theo lực đã tính.
  - Nếu như bóng chạm vào vật thể thì sẽ đi theo hướng ngược lại của tọa độ đã tính.
  - Tốc độ của bóng sẽ giảm dần theo hàm thời gian.
  - Khi bóng đi đến vị trí chỉ định thì clear màn hình và chuyển qua level tiếp theo.
# 3.Mô tả các chức năng đã cài đặt, kèm video minh họa

  - Có màn hình bắt đầu game.
  - Thiết kế hệ thống level.
  - Tính điểm.
  - Màn hình kết thúc game.
## Link video:https://youtu.be/VCAriTPZoUc
# 4.Các kỹ thuật lập trình được sử dụng trong chương trình

  - Sử dụng mảng và vecor để tạo ra bóng cũng như các lỗ golf và xấy level.
  - Dùng class để tách 1 số file.
  - Cách set up môi trường, tích hợp thư viện.
  - Bước đầu sử dụng SDL2, sử dụng ảnh và âm thanh.
# 5.Kết luận, hướng phát triển và các điều tâm đắc rút ra được sau khi hoàn thiện chương trình

## Kết luận

  - Tìm hiểu và tiếp thu kiến thức về SDL2 tại: lazyfoo.net/tutorials/SDL/
  - Cơ chế hoạt động và logic game, hình ảnh tham khảo từ: https://github.com/PolyMarsDev/Twini-
## Hướng phát triển

  - Mở rộng thêm menu (Highscore, music on/off, replay, continue).
  - Làm thêm âm thanh nền.
  - Mở rộng thêm các level.
 ## Điều rút ra sau khi làm game
 
  - Hiểu thêm cách làm 1 game đơn giản.
  - Biết thêm về thư viện SDL2 và cách code cũng như clean code.
  - Vẫn chưa chia file 1 cách triệt để.
