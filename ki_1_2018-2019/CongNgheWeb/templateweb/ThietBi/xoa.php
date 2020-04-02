<?php
	$link=mysqli_connect('127.0.0.1', 'root', '') or die('Khong the ket noi den CSDL MySQL');
	mysqli_select_db($link, 'DULIEU');
	$sql='SELECT * FROM phongban';
	$result=mysqli_query($link, $sql);
	echo "<table border = '1' width = '100%'>";
	echo "<caption>Du lieu truy xuat tu bang phongban</caption>";
	echo "<tr><th>IDPB</th><th>TenPB</th><th>MoTa</th><th>Xoa</th></tr>";
	while($row=mysqli_fetch_array($result,true)) {
		$idpb = $row{'IDPB'};
		$tenpb = $row{'TenPB'};
		$mota = $row{'Mota'};
		echo "<tr><td>$idpb</td><td>$tenpb</td><td>$mota</td><td align = 'center'><a href = 'xulyxoa.php?IDPB=".$row['IDPB']."'>xoa</a></td></tr>";
	}
	echo "</table>";
?>