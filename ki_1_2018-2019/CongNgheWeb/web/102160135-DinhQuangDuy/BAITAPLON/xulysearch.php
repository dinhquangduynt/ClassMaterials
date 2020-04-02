<?php 
	$ten=$_POST['t1'];
	
	$link= mysqli_connect("localhost", "root", "") or die("khong the ket noi den CSDL MySQL");
	mysqli_set_charset($link,"UTF8");
	mysqli_select_db($link,"DULIEU");
	if(isset($ten)){	
		$sql="select *from thongtinphong WHERE tennguoidat like '%$ten' OR tennguoidat like '$ten%' OR maphong like '%$ten' OR maphong like '$ten%'";
	}
	$rs=mysqli_query($link,$sql);

	if (mysqli_num_rows($rs) == 0)
	{
		echo '<script language="javascript">alert("Không có thông tin"); 
            window.location="form_search.php";</script>';
	}
	else{
		echo '<table border="1" width="100%">';
		echo '<caption>Dữ Liệu Tìm Kiếm</Caption>';
		echo "<TR><TH>Mã Phòng</TH><TH>Loại Phòng</TH><TH>Số Người Tối Đa</TH><TH>Tình Trạng</TH><TH>Tên Người Đặt</TH> <TH>Ngày Nhận</TH> <TH>Ngày Trả</TH></TR>";

		while ($row=mysqli_fetch_array($rs,MYSQLI_BOTH)) {
		# code...

			echo '<tr>
			<td align ="center">'.$row['maphong'].'</td>
			<td align ="center">'.$row['loaiphong'].'</td>
			<td align ="center">'.$row['songuoitoida'].'</td>
			<td align ="center">'.$row['tinhtrang'].'</td>
			<td align ="center">'.$row['tennguoidat'].'</td>
			<td align ="center">'.$row['ngaydatphong'].'</td>
			<td align ="center">'.$row['ngaytraphong'].'</td>
			</tr>';
		}

	echo '</TABLE>';
	}
 ?>