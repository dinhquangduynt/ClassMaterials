<!DOCTYPE html>
<html>
    <head>
        <title>Quản lý thiết bị</title>
        <meta charset="utf-8">
        <link rel="stylesheet" type="text/css" href="assets/css/font-awesome.min.css">
        <link rel="stylesheet" type="text/css" href="assets/css/bootstrap.min.css">
        
        <script  src="assts/js/jquery-3.2.1.min.js"></script>
        <script  src="assts/js/bootstrap.min.js"></script>
        <!---->
        <link rel="stylesheet" type="text/css" href="assets/css/slick.css"/>
        <link rel="stylesheet" type="text/css" href="assets/css/slick-theme.css"/>
        <!--slide-->
        <link rel="stylesheet" type="text/css" href="assets/css/style.css">
        
    </head>
     <?php
        include 'config.php';
        include 'Process_db.php';
    ?>       
    <body>
        <div id="header">
                <div class="container">
                    <div class="row" id="header-main"> 
                        <div class="col-md-3">
                             <img src="anh/2.jpg" width="270px" height="130px">
                        </div>

                        
                        <div class="col-md-6">
                            <p ><marquee style="color: blue; font-size: 50px; font-weight: bold; margin-top: 25px;">Quản lý phòng ban</marquee></p>
                        </div>
                     
                        <div class="col-md-3">
                            <img src="anh/3.jpg" width="270px" height="130px">
                        </div>
                    </div>
                </div>
            </div>
            
            
                    <form style="margin-top: 10px; margin-left: 880px" action="xulylogin.php" method="post" target="_top">
                        <ul id="menu-main">
                             <li>
                                <p style="color: black; font-size: 15px">User name:</p>
                            </li>
                            <li style="margin-left: 10px">
                                <input style="width: 100px" type="text" name="t1">
                            </li>
                            <li style="margin-left: 10px">
                                <p style="color: black; font-size: 15px">Password:</p>
                            </li>
                            <li style="margin-left: 10px">
                                <input style="width: 100px" type="password" name="p1">
                            </li>
                            <li style="margin-left: 10px">
                                <input style="width: 50px" type="submit" name="sub" value="Login">
                            </li>
                        </ul>
                    </form>
                
            
        </body>
    </html>