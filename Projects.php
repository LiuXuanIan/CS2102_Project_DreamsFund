<?php
	session_start();
	if($_SESSION[page_number] == NULL){
		$_SESSION[page_number] = 1;
	}
?>

<!DOCTYPE HTML>
<html>
	<head>
	<meta charset="utf-8">
	<meta http-equiv="X-UA-Compatible" content="IE=edge">
	<title>Orange &mdash; Free Website Template, Free HTML5 Template by FreeHTML5.co</title>
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<meta name="description" content="Free HTML5 Website Template by FreeHTML5.co" />
	<meta name="keywords" content="free website templates, free html5, free template, free bootstrap, free website template, html5, css3, mobile first, responsive" />
	<meta name="author" content="FreeHTML5.co" />

	<meta property="og:title" content=""/>
	<meta property="og:image" content=""/>
	<meta property="og:url" content=""/>
	<meta property="og:site_name" content=""/>
	<meta property="og:description" content=""/>
	<meta name="twitter:title" content="" />
	<meta name="twitter:image" content="" />
	<meta name="twitter:url" content="" />
	<meta name="twitter:card" content="" />

	<link href='https://fonts.googleapis.com/css?family=Work+Sans:400,300,600,400italic,700' rel='stylesheet' type='text/css'>
	<link href="https://fonts.googleapis.com/css?family=Playfair+Display:400,700" rel="stylesheet">
	
	<!-- Animate.css -->
	<link rel="stylesheet" href="css/animate.css">
	<!-- Icomoon Icon Fonts-->
	<link rel="stylesheet" href="css/icomoon.css">
	<!-- Bootstrap  -->
	<link rel="stylesheet" href="css/bootstrap.css">
	<!-- Theme style  -->
	<link rel="stylesheet" href="css/style.css">

	<!-- Modernizr JS -->
	<script src="js/modernizr-2.6.2.min.js"></script>
	<!-- FOR IE9 below -->
	<!--[if lt IE 9]>
	<script src="js/respond.min.js"></script>
	<![endif]-->

	</head>
	<body>
		
	<div class="fh5co-loader"></div>
	
	<div id="page">
	<nav class="fh5co-nav" role="navigation">
		<div class="container">
			<div class="row">
				<div class="col-xs-5 text-right menu-1">
					<ul>
						<li><a href="about.html">About Us</a></li>
						<li class="has-dropdown">
							<a href="Projects.html">Projects</a>
							<ul class="dropdown">
								<li><a href="#">Ongoing</a></li>
								<li><a href="#">Successful</a></li>
							</ul>
						</li>
					</ul>
				</div>
				<div class="col-xs-2 text-center">
					<div id="fh5co-logo"><a href="index.html">DreamsFund</a></div>
				</div>
				<div class="col-xs-5 text-left menu-1">
					<ul>
						<li class="has-dropdown">
							<a href="#">Get started</a>
							<ul class="dropdown active">
								<li><a href="#">Initiate</a></li>
								<li><a href="#">Invest</a></li>
							</ul>
						</li>
						<li><a href="contact.html">Sign in</a></li>
					</ul>
				</div>
			</div>
			
		</div>
	</nav>

	<header id="fh5co-header" class="fh5co-cover fh5co-cover-sm" role="banner" style="background-image:url(images/img_bg_2.jpg);">
		<div class="overlay"></div>
		<div class="container">
			<div class="row">
				<div class="col-md-8 col-md-offset-2 text-center">
					<div class="display-t">
						<div class="display-tc animate-box" data-animate-effect="fadeIn">
							<h1>Our projects here!</h1>
							<h2>Scroll down to find out more!</h2>
						</div>
					</div>
				</div>
			</div>
		</div>
	</header>

	<div id="fh5co-services">
		<div class="container">
			<div class="row">
				<div class="col-md-5 col-md-push-1 animate-box">
					<div class="sidenav">
						<h3>Categories</h3>
						<ul>
						<li><a href="#">Restaurant, Cafe and Bakery</a></li>
						<li><a href="#">Medical and Health Care</a></li>
						<li><a href="#">Retail and Online Store</a></li>
						<li><a href="#">Services</a></li>
						<li><a href="#">Others</a></li>
					</div>
				</div>
				<div class="row">
					<?php
						$begin  = ($_SESSION[page_number] - 1)*10;
					    $db     = pg_connect("host=localhost port=5432 dbname=CrowdFunding user=postgres password=LX990204!");	
						$result = pg_query($db, "SELECT * FROM project_initiated_by LIMIT 10 OFFSET ".$begin);		// Query template
						$row    = pg_fetch_all($result);
						$total  = count($row);

						$current_page = $_SESSION[page_number];
						$total_page;
						if ($total%10 == 0) {
							$total_page = $total/10;
						} else {
							$total_page = $total/10 + 1;
						}
						echo "page".$current_page;
						for ($x = 0; $x <10; $x++){
							echo "
							<div class='col-lg-4 col-md-4'>
							<div class='fh5co-blog animate-box' data-animate-effect='fadeIn'>
								<a href='#'><img class='img-responsive' src='images/work-4.jpg'></a>
								<div class='blog-text'>
								<h3>".$row[$x][title]."</h3>
								<span class='posted_on'>".date_format($row[$x][startdate],"Y/m/d")."</span>
								<span class='comment'><a href=''>".$row[$x][current_funding]."<i class='icon-speech-bubble'></i></a></span>
								<p>".$row[$x][description]."</p>
								<a href='projectDetails.php' class='btn btn-primary'>Read More</a>
								</div>
							</div>
							</div>";

							$_SESSION[projectid] = $row[$x][projectid];
						}
						echo "
						<form action='Projects.php' method='POST'>
							<input type='text' name='page_NUM' value='1'/>
							<input type='submit' name='go'/>
						</form>
						";
						if(isset($_POST['go'])) {
							$_SESSION[page_number] = $_POST[page_NUM];
							echo "<meta http-equiv='refresh' content='0; URL = Projects.php'/>";
						}

					?>
				</div>
			</div>
		</div>
	</div>


	<div id="fh5co-started">
		<div class="container">
			<div class="row animate-box">
				<div class="col-md-8 col-md-offset-2 text-center fh5co-heading">
					<h2>Lets Get Started</h2>
					<p>Dignissimos asperiores vitae velit veniam totam fuga molestias accusamus alias autem provident. Odit ab aliquam dolor eius.</p>
				</div>
			</div>
			<div class="row animate-box">
				<div class="col-md-8 col-md-offset-2">
					<form class="form-inline">
						<div class="col-md-6 col-md-offset-3 col-sm-6">
							<button type="submit" class="btn btn-default btn-block">Get In Touch</button>
						</div>
					</form>
				</div>
			</div>
		</div>
	</div>

	<footer id="fh5co-footer" role="contentinfo">
		<div class="container">
			<div class="row row-pb-md">
				<div class="col-md-2 col-sm-4 col-xs-6">
					<ul class="fh5co-footer-links">
						<li><a href="#">About</a></li>
						<li><a href="#">Help</a></li>
						<li><a href="#">Contact</a></li>
						<li><a href="#">Terms</a></li>
						<li><a href="#">Meetups</a></li>
					</ul>
				</div>

				<div class="col-md-2 col-sm-4 col-xs-6">
					<ul class="fh5co-footer-links">
						<li><a href="#">Shop</a></li>
						<li><a href="#">Privacy</a></li>
						<li><a href="#">Testimonials</a></li>
						<li><a href="#">Handbook</a></li>
						<li><a href="#">Held Desk</a></li>
					</ul>
				</div>

				<div class="col-md-2 col-sm-4 col-xs-6">
					<ul class="fh5co-footer-links">
						<li><a href="#">Find Designers</a></li>
						<li><a href="#">Find Developers</a></li>
						<li><a href="#">Teams</a></li>
						<li><a href="#">Advertise</a></li>
						<li><a href="#">API</a></li>
					</ul>
				</div>
				<div class="col-md-5 col-md-push-1 animate-box">
					
					<div class="fh5co-contact-info">
						<h3>Contact us</h3>
						<ul>
							<li class="address">Singapore, <br>Smith Avenue, <br> Block 17</li>
							<li class="phone">+65 1234 5678</li>
							<li class="email"><a href = "#">DreamsFund@gmail.com</a></li>
							<li class="url"><a href = "#">DreamsFund.com</a></li>
						</ul>
					</div>

				</div>
			</div>

			<div class="row copyright">
				<div class="col-md-12 text-center">
					<p>
						<small class="block">&copy; 2018 DreamsFund. All Rights Reserved.</small> 
					</p>
					<p>
						<ul class="fh5co-social-icons">
							<li><a href="#"><i class="icon-twitter"></i></a></li>
							<li><a href="#"><i class="icon-facebook"></i></a></li>
							<li><a href="#"><i class="icon-linkedin"></i></a></li>
							<li><a href="#"><i class="icon-dribbble"></i></a></li>
						</ul>
					</p>
				</div>
			</div>

		</div>
	</footer>
	</div>

	<div class="gototop js-top">
		<a href="#" class="js-gotop"><i class="icon-arrow-up"></i></a>
	</div>
	
	<!-- jQuery -->
	<script src="js/jquery.min.js"></script>
	<!-- jQuery Easing -->
	<script src="js/jquery.easing.1.3.js"></script>
	<!-- Bootstrap -->
	<script src="js/bootstrap.min.js"></script>
	<!-- Waypoints -->
	<script src="js/jquery.waypoints.min.js"></script>
	<!-- Main -->
	<!-- Google Map -->
	<script src="https://maps.googleapis.com/maps/api/js?key=AIzaSyCefOgb1ZWqYtj7raVSmN4PL2WkTrc-KyA&sensor=false"></script>
	<script src="js/google_map.js"></script>

	<script src="js/main.js"></script>

	</body>
</html>