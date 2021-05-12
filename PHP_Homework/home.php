<html>

<head>
    <title> Monolith HomeWork </title>
</head>
<body>

    <h3> Monolith HomeWork </h3>
    <hr>
    <div id="menu">
    <span style="padding-right:25px;"><a href="home.php?page=Q1">Question 1</a></span>
        <a href="home.php?page=Q2">Question 2</a>
    </div>
</br></br>

    <div id="content">  
   
<?php  
 $p = $_GET['page'];  
   
$page = "source/".$p.".php";  

if(file_exists($page))  
    include($page);  
elseif($p=="")  
    echo "This is Home Page";  
else  
    echo "what are you looking for! ?";  
   
?>  
  </div>  
</body>
</html>
