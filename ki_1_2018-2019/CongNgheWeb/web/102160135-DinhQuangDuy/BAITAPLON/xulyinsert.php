<?php 
	$maphong=$_POST['txtMaphong'];
	$loaiphong=$_POST['txtLoaiphong'];
	$songuoi=$_POST['txtsonguoi'];
	$ten=$_POST['txtten'];
	$ngaynhan=$_POST['ngaynhan'];
	$ngaytra=$_POST['ngaytra'];


	$link = mysqli_connect("localhost", "root", "") or die("khong the ket noi den CSDL MYSQL");
	mysqli_set_charset($link,"UTF8");
	mysqli_select_db($link,"DULIEU");
	$rs1=mysqli_query($link, "select maphong from thongtinphong where maphong= '$maphong'");
	if (mysqli_num_rows($rs1)==0) {
		$sql ="insert into thongtinphong(maphong,loaiphong,songuoitoida,tinhtrang,tennguoidat,ngaydatphong,ngaytraphong) 
		values ('$maphong','$loaiphong','$songuoi','Đã đặt','$ten','$ngaynhan','$ngaytra')";
		$rs=mysqli_query($link,$sql);

		$add="update loaiphong set soluongphong = soluongphong + 1 where maloaiphong ='$loaiphong'";
		$rs2=mysqli_query($link,$add);
		header("Location:insert_room.php");
	}
	else
		{echo '<script language="javascript">alert("Mã phòng đã tồn tại"); 
            window.location="form_insert_room.php";</script>';
        }


 ?>