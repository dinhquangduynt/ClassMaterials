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
        <div id="wrapper">
            <!---->
            <!--HEADER-->
            <div id="header">
                <div class="container">
                    <div class="row" id="header-main"> 
                        <div class="col-md-3">
                             <img src="anh/2.jpg" width="270px" height="200px">
                        </div>

                        
                        <div class="col-md-6">
                            <p ><marquee style="color: blue; font-size: 50px; font-weight: bold; margin-top: 25px;">Quản lý phòng ban</marquee></p>
                        </div>
                     
                        <div class="col-md-3">
                            <img src="anh/3.jpg" width="270px" height="200px">
                        </div>
                    </div>
                </div>
            </div>
            <!--END HEADER-->
       <!--MENU-->
            <div id="menunav">
                <div class="container">
                    <nav>
                        <div class="home pull-left">
                            <a href="index.php">Trang chủ</a>
                        </div>
                        <!--menu main-->
                        <ul id="menu-main">
                             <li>
                                <a href="admin/register.php">Đăng ký</a>
                            </li>
                            <li>
                                <a href="admin/login.php">Đăng nhập</a>
                            </li>
                            <li>
                                <a href="gioithieu.php">Giới thiệu</a>
                            </li>
                            <li>
                                <a href="Lienhe.php">Liên hệ</a>
                            </li>
                        </ul>
            
                    </nav>
                </div>
            </div>
            <!--ENDMENU-->
            <!--DANH MUC & SAN PHAM MOI-->
            <div id="maincontent">
                <div class="container">
                    <div class="col-md-3  bor" >
                        <div class="box-left box-menu" >
                            <h3 class="box-title"><i class="fa fa-list"></i>  Danh mục</h3>
                            <ul>
                              <li>
                                <a href="xemthongtinpb.php" target="main">Xem thông tin</a>
                            </li>
                            <li>
                                <a href="admin/login.php">Đăng nhập</a>
                            </li>
                            <li>
                                <a href="gioithieu.php">Giới thiệu</a>
                            </li>
                            <li>
                                <a href="Lienhe.php">Liên hệ</a>
                            </li>
                            </ul>
                        </div>

                          
                    </div>
                    <!--ADD DANH MUC & SAN PHAM MOI-->
                    <!--LIST SAN PHAM-->
                    <div class="col-md-6 bor" name="main">
                        <section id="slide" class="text-center" >
                            <img src="upload/windows-10-heaven.png" class="img-thumbnail" width="10px" height="10px">
                        </section>

                        <section class="box-main1">
                            <?php 
                            if(isset($_GET['page'])){$page=$_GET['page'];}else{$page="";}


                            switch($page)
                                {
                                
                                
                                case "list-thiet-bi":
                                
                                    include("include/list-thiet-bi.php");


                                break;
                                
                                case "chi-tiet-thiet-bi":
                                    include("include/chi-tiet-thiet-bi.php");
                                break;
                                 case "login":
                                    include("login.php");
                                break;
                                default:
                                    include("include/TrangChu.php");
                                    
                                }

                        
                        ?>
                       
            </section>

        </div>
        <div class="col-md-3  bor" >

                        <div class="box-left box-menu" >
                            <ul>
                                 <li><img src="anh/1.jpg" width="210px" height="160px"></li>
                                 <li><img src="anh/1.jpg" width="210px" height="160px"></li>
                                 <li><img src="anh/1.jpg" width="210px" height="160px"></li>
                            </ul>
                        </div>

              
                    </div>
       </div>
                <!--ADD LIST SAN PHAM-->
             <!--FOOTER-->
                <div class="container-pluid">
                <section id="footer">
                    <div class="container">
                        <div class="col-md-3" id="shareicon">
                            <ul>
                                <li>
                                    <a href="https://www.facebook.com/maradona.kieu.3"><i class="fa fa-facebook"></i></a>
                                </li>
                                <li>
                                    <a href="http://daotaocep.edu.vn/"><i class="fa fa-twitter"></i></a>
                                </li>
                                <li>
                                    <a href="http://daotaocep.edu.vn/"><i class="fa fa-google-plus"></i></a>
                                </li>
                                <li>
                                    <a href="https://www.youtube.com/channel/UCd4_KsvuEsfGjaVAEiR2GgQ?view_as=subscriber"><i class="fa fa-youtube"></i></a>
                                </li>
                            </ul>
                        </div>
                    </div>
                </section>
                <section id="footer-button">
                    <div class="container-pluid">
                        <div class="container">
                             <div id="footer_wrapper">
                <span style="font-family:arial,helvetica,sans-serif;"><span style="font-size: 130%;">
                <span style="color:#FFF;">
                <p style="float:left;padding-top:2%; width:60%">
                    <span style="font-size:130%;"><span style="font-family:tahoma,geneva,sans-serif;"><span style="color:#00bcf2;"><b>CÔNG TY TNHH MYKIEU COMPUTER & MOBILE</b></span></span></span><br>
                    <strong style="font-family: tahoma, geneva, sans-serif;"><u>Địa chỉ</u></strong><span style="font-family: tahoma, geneva, sans-serif;">: 143 Nguyễn Lương Bằng - TP. Đà Nẵng</span><br>
                    <strong style="font-family: tahoma, geneva, sans-serif;"><u>Số điện thoại</u></strong><span style="font-family: tahoma, geneva, sans-serif;">: 01238718650</span><br>
                    <u style="font-family: tahoma, geneva, sans-serif;">Website</u><span style="font-family: tahoma, geneva, sans-serif;">: </span><span style="font-family: tahoma, geneva, sans-serif; color:#00bcf2;">www.quanlythietbi.vn</span>                  
                </p>
                </span>             
        </div>
        <!--End #footer_wrapper-->
                        </div>
                </section>
            </div>
        </div>      
    </div>
            </div>      
        </div>
    <script  src="assets/js/slick.min.js"></script>

    </body>
        
</html>

<script type="text/javascript">
    $(function() {
        $hidenitem = $(".hidenitem");
        $itemproduct = $(".item-product");
        $itemproduct.hover(function(){
            $(this).children(".hidenitem").show(100);
        },function(){
            $hidenitem.hide(500);
        })
    })
</script>                     