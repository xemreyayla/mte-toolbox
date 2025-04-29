[EN](mte-toolbox-user-manuel-[EN])
[TR](mte-toolbox-kullanim-kilavuzu-[TR])

## mte-toolbox User Manuel [EN]

This section explains how to run the application.

### Getting Started 
This section introduces the application pages.

#### Executing program

##### Connection Page 
The first page that will be displayed when the program opens is the connection page. When the program starts, if a serial adapter (similar to USB) is connected to the computer, it will be automatically detected and listed under the "Active Ports" section.
To establish a connection, select the desired port from the list and click the Connect button. Afterward, a notification will appear confirming that port connection has been successfully established.
The Refresh button is used to re-scan and list currently active and available ports.
To terminate the connection, click the Disconnect button. It is recommended to disconnect before changing devices or exiting the application.

![connection_page](https://github.com/user-attachments/assets/8da2219e-da7f-4d08-99e3-157ae41ff0e1)

##### Device Info Page 
If the device connection is not established, the other pages of the program will not function. If no conncetion has been made, a warning message will appear to inform the user that establishing a connection is required.
On the Device Info Page, it is possible to access all the device information shown in the image below. To view this information, simply navigate to the Device Info Page.

![deviceinfo_page](https://github.com/user-attachments/assets/b58b4733-04d3-4e16-b66b-64d82e465233)

##### Utilities Page
The GET STATUS button on the Utilities Page reads the status of all input and output GPIOs. 
The SD CARD FORMAT button formats the SD Card of the connected device and provides feedback to user. If the formatting is successful, both visual and audible feedback are provided. 
Each output has its own SET LOW/SET HIGH buttons, wich are used to set the output state to LOW (0) or HIGH (1). 
Additionally, as shown in the image below, the top left corner of the page displays information about the device connection and the formatting process.

![utilities_page](https://github.com/user-attachments/assets/56cd4652-b3b4-4b37-bffc-a36f02989b9f)

##### Console Page
The Console Page consists of two sections:
The first is the bottom bar where commands are entered;
The second is the upper large window where the outputs of the commands are displayed. 
Thanks to the embedded terminal on this page, necessary commands can be sent directly without the need to connect to the device with an external terminal on the device itself.

![console_page](https://github.com/user-attachments/assets/aa42f2e6-f20e-4aa0-b6b9-7e419ef7f1c9)




---




## mte-toolbox Kullanım Kılavuzu [TR]

Bu bölümde uygulamanın nasıl çalıştırılacağı açıklanmıştır.

### Başlarken 
Bu bölümde uygulama sayfaları tanıtılmıştır.

#### Programı Çalıştırmak

##### Connection Sayfası
Program açıldığında ilk olarak bağlantı sayfası görüntülenmektedir. Bilgileri alınmak istenen cihaz, seri port adaptörü (USB'ye bezer) aracaılğıyla bilgisayara bağlandığında, bu bağlantı otomatik olarak algılanmakta ve aktif portlar "Active Ports" bölümünde listelenmektedir.
Bağlantı kurmak için, listeden istenilen port seçilmeli ve ardından Connect butonuna tıklanmalıdır. Bağlantı başarılı bir şekilde kurulduğunda, bu durumu bildiren bir uyarı kullanıcıya gösterilecektir.
Refresh butonu, o an aktif ve kullanılabilir durumda olan portları tekrar tarayarak listelemek için kullanılmaktadır. 
Bağlantıyı sonlandırmak için Disconnect butonuna tıklanmalıdır. Chihaz değişikliği yapmadan ya da uygulamadan çıkmadan önce bağlantının kesilmesi tavsiye edilmektedir. 


![connection_page](https://github.com/user-attachments/assets/8da2219e-da7f-4d08-99e3-157ae41ff0e1)

##### Device Info Sayfası
Eğer cihaz bağlantısı gerçekleşmemişse, programın diğer sayfaları işlevsel olmayacaktır. Bağlantı yapılmadığı durumlarda, kullanıcıya bağlantının zorunlu olduğunu belirten bir uyarı mesajı gösterilmektedir. Aşağıda yer alan görselde de görüldüğü üzere Device Info Sayfası üzerinden tüm cihaz bilgilerine ulaşmak mümkündür.
Bu bilgilere erişmek için yalnızca Device Info Sayfasına geçilmesi yeterlidir.

![deviceinfo_page](https://github.com/user-attachments/assets/b58b4733-04d3-4e16-b66b-64d82e465233)

##### Utilities Sayfası
Utilites Sayfasındaki GET STATUS butonu, tüm input ve output GPIO'ların durumlarını okumaktadır. 
SD CARD FORMAT butonu, bağlı cihazın SD Kartını formatlamakta ve kullanıcıya bili vermektedir. Formatlama işlemi başarılı olursa, hem görsel hem de sesli bildirim sağlanmaktadır.
Her output için, çıktının durumunu LOW(0) veya HIHG(1) yapmak amacıyla kullanılan SET LOW/SET HIGH butonları mevcuttur.
Ayrıca aşağıda yer alan görselde de görülebileceği gibi sayfanın sol üst kısmında cihaz bağlantısı ve formatlama sürecine dair bilgiler yer almaktadır.

![utilities_page](https://github.com/user-attachments/assets/56cd4652-b3b4-4b37-bffc-a36f02989b9f)

##### Console Sayfası
Console Sayfası iki bölümden oluşmaktadır;
Birincisi, komutların girilmesi için ayrılmış olan alt kısımda yer alan satırdır.
İkincisi ise, girilen komutların çıktılarının görüntülendiği üst kısımda yer alan geniş penceredir. 
Bu sayfada yer alan gömülü terminal sayesinde, cihaza harici bir terminal ile bağlanmaya ya da cihazın kendi ekranında terminal açmaya gerek kalmadan gerekli komutlar doğrudan gönderilebilmektedir. 

![console_page](https://github.com/user-attachments/assets/aa42f2e6-f20e-4aa0-b6b9-7e419ef7f1c9)










