<?php
include('ayar1453.php');
session_start();
$kid=$_SESSION["kId"];
$gelennesnesi = mysqli_query($bag,"SELECT kAdi FROM kullanicilar WHERE md5(kId)='$kid'");
if(mysqli_num_rows($gelennesnesi)==0)
{
	header('Location: index.php');
}
else
{
	$dizi= mysqli_fetch_row($gelennesnesi);
	$kadi=$dizi[0];
	
} 
?>
<html>
<head>
<link rel="stylesheet" type="text/css" href="style.css">
<title>e-Kutu</title>
</head>
<body>
    <table><tr><a href="https://www.afad.gov.tr" target="_blank"><img class="elogo" src="img/ekutu.png" alt=""></a></tr></table>
	<table><tr><a href="index.php"><img class="admin" src="img/admin.png" alt=""></a></tr></table>
   <form class="form2" name="form"  action="index.php" method="post">
    
		<table border="0">
		<tr><td> 
				<?php
				$gelennesnesi = mysqli_query($bag,"SELECT * FROM sicakliklar ORDER BY sicakliklar.sTime ASC");
					echo "<table class='tb2' >";    
					echo "<tr>";
					echo "<th class='th'>";
					echo date("d.M.Y");
					echo "</th>";
					echo "<th class='th'>";
					echo "e-Kutu";
					echo "</th>";
					echo "<th class='th'>"; 
					echo date("H:i:s", time()).'<br>';
					echo "</th>";
					echo "</tr>";					
					echo "</table>";
					
					
					echo "<table class='tbl'>";	
					echo "<tr>";					
					echo "<th class='th'>"; "<td class='td'>";echo("Tarih ve Saat");echo "</td>";echo "</th>";
					echo "<th class='th'>";"<td class='td'>";echo("Durum");echo "</td>";echo "</th>";
					echo "<th class='th'>";"<td class='td'>";echo("Konum");echo "</td>";echo "</th>";
					echo "<th class='th'>";"<td class='td'>";echo("CO2");echo "</td>";echo "</th>";
					echo "</tr>";
					
				while($satir = mysqli_fetch_row($gelennesnesi))
				{ 
					echo "<tr>";
					echo "<td class='td'>";echo date("H:i:s----d.M.Y",$satir[1]);echo "</td>";
					echo "<td class='td'>";echo $satir[2];echo "</td>";
					echo "<td class='td'>";echo $satir[3];echo "</td>"; 
					echo "<td class='td'>";echo $satir[4];echo "</td>";
					echo "</tr>";
				
				}
					
					echo "</table>";
				?>
		</table>
      <a href ="cikis.php">Çıkış Yap </a>
   </form>
   
       

</body>

 </html>
