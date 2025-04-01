一、客户端开发
可视化界面：采用QT进行图形用户界面（GUI）开发，提供直观易用的操作体验。
1.	视频播放器：结合FFmpeg和SDL库，实现高效稳定的视频解码与播放功能，支持HLS协议以适应流媒体传输需求。
2.	网络通信：使用QT内置的QNetworkAccessManager类处理HTTP请求，确保与服务端的信息交互安全可靠。
二、服务端开发
1. 选用 Boost.Beast 搭建基于HTTP/HTTPS的高性能Web服务器，利用其异步I/O特性提升并发处理能力。
2. 采用HLS（HTTP Live Streaming）协议将视频流分割为多个小文件，允许客户端边下载边播放，提高观看流畅度。
三、数据管理
1. 使用MySQL存储结构化数据，包括用户信息表（用户名、密码、性别、账号及上传视频编号集）和视频信息表（标题、编号、简介、封面图片、分类、存储地址等）。数据关系E-R图如下图1.
四、流媒体服务器
   部署srs实现视频文件的推流与拉流
具体效果：
![image](https://github.com/user-attachments/assets/25653d35-e0e4-438c-8d11-d17f00ee412f)
播放器效果：
![image](https://github.com/user-attachments/assets/4b2c9eb0-6dba-4f3e-bfb9-9fc322b8ddb5)


