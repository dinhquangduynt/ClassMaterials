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
        <div class="col-md-3  bor" >
                        <div class="box-left box-menu" >
                            <h3 class="box-title"><i class="fa fa-list"></i>  Danh mục</h3>
                            <ul>
                              <li>
                                <a href="xemthongtinpb.php" target="t3">Xem phòng ban</a>
                            </li>
                            <li>
                                <a href="xemthongtinNVPB.php" target="t3">Xem nhân viên</a>
                            </li>
                            <li>
                                <a href="timkiem.php" target="t3">Tìm kiếm phòng ban</a>
                            </li>
                            </ul>
                        </div>

                          
                    </div>
                </body>
            </html>