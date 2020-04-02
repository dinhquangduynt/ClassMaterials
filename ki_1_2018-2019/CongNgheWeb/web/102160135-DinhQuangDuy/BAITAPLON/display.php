<?php 
//khai bao ket noi
	$link= mysqli_connect("localhost", "root", "") or die("khong the ket noi den CSDL MySQL");
	mysqli_set_charset($link,"UTF8");
	mysqli_select_db($link,"DULIEU");
	$sql = "select *from LOAIPHONG";
	$result= mysqli_query($link,$sql);

	echo '<table border="1" width="100%">';
	echo '<caption>Dữ Liệu Loại Phòng</Caption>';
//tieu de cua bang chua du lieu  khi hienthi trang web

	echo "<TR><TH>Mã Loại Phòng</TH><TH>Số Lượng Phòng</TH><TH>giá tiền(1 Ngày)</TH><TH>Mô tả</TH><TH>Xem Thông Tin</TH> </TR>";

//cach 2: su dung hieu qua hon 

	while ($row=mysqli_fetch_array($result,MYSQLI_BOTH)) {
	# code...
	
		echo '<tr>
		<td>'.$row['maloaiphong'].'</td>
		<td>'.$row['soluongphong'].'</td>
		<td>'.$row['giatien'].'</td>
		<td>'.$row['mota'].'</td>
		<td align ="center">
		<a href="display_room.php?ID='.$row['maloaiphong'].'">Xem Thông Tin</a>
		</td></tr>';
	}

	echo '</TABLE>';
	mysqli_free_result($result);
	mysqli_close($link);

 ?>