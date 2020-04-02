-- phpMyAdmin SQL Dump
-- version 4.8.3
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Dec 20, 2018 at 03:29 PM
-- Server version: 10.1.36-MariaDB
-- PHP Version: 7.2.11

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `dulieu`
--

-- --------------------------------------------------------

--
-- Table structure for table `admin`
--

CREATE TABLE `admin` (
  `Username` varchar(50) COLLATE utf8_unicode_ci NOT NULL,
  `password` text COLLATE utf8_unicode_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `admin`
--

INSERT INTO `admin` (`Username`, `password`) VALUES
('dinhquangduy', '123456'),
('duy123', '123');

-- --------------------------------------------------------

--
-- Table structure for table `customer`
--

CREATE TABLE `customer` (
  `User` varchar(50) COLLATE utf8_unicode_ci NOT NULL,
  `Password` text COLLATE utf8_unicode_ci NOT NULL,
  `Hoten` text COLLATE utf8_unicode_ci NOT NULL,
  `SDT` varchar(10) COLLATE utf8_unicode_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `customer`
--

INSERT INTO `customer` (`User`, `Password`, `Hoten`, `SDT`) VALUES
('dinhquangduynt', '123456', 'Đinh Quang Duy', '0977694163'),
('quangduy123', '123456', 'Nguyễn Quang Duy', '0977665554');

-- --------------------------------------------------------

--
-- Table structure for table `loaiphong`
--

CREATE TABLE `loaiphong` (
  `maloaiphong` varchar(10) COLLATE utf8_unicode_ci NOT NULL,
  `soluongphong` int(11) NOT NULL,
  `giatien` double NOT NULL,
  `mota` text COLLATE utf8_unicode_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `loaiphong`
--

INSERT INTO `loaiphong` (`maloaiphong`, `soluongphong`, `giatien`, `mota`) VALUES
('STD', 4, 400000, 'tivi truyền hình cáp'),
('VIP', 4, 700000, 'Phòng điều hòa, tivi truyền hình cáp...');

-- --------------------------------------------------------

--
-- Table structure for table `nhansu`
--

CREATE TABLE `nhansu` (
  `maso` text COLLATE utf8_unicode_ci NOT NULL,
  `hoten` text COLLATE utf8_unicode_ci NOT NULL,
  `ngaysinh` date NOT NULL,
  `nghenghiep` text COLLATE utf8_unicode_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `nhansu`
--

INSERT INTO `nhansu` (`maso`, `hoten`, `ngaysinh`, `nghenghiep`) VALUES
('mso1', 'Lê A', '2018-11-13', 'công nhân'),
('ms02', 'Nguyễn B', '2018-11-06', 'Kỹ Sư'),
('ms03', 'Trần C', '2018-11-22', 'Nhân Viên'),
('ms04', 'Mạc D', '2018-11-13', 'Sinh Viên');

-- --------------------------------------------------------

--
-- Table structure for table `nhanvien`
--

CREATE TABLE `nhanvien` (
  `IDNV` varchar(20) COLLATE utf8_unicode_ci NOT NULL,
  `Hoten` text COLLATE utf8_unicode_ci NOT NULL,
  `IDPB` varchar(20) COLLATE utf8_unicode_ci NOT NULL,
  `Diachi` text COLLATE utf8_unicode_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `nhanvien`
--

INSERT INTO `nhanvien` (`IDNV`, `Hoten`, `IDPB`, `Diachi`) VALUES
('NV01', 'Nguyen Van A', 'PB01', 'Dana'),
('NV02', 'Tran B', 'PB02', 'QNam'),
('NV03', 'Le Van C', 'PB03', 'QNgai'),
('NV04', 'Dinh Ngoc D', 'PB01', 'QBinh'),
('NV05', 'Tran Dinh E', 'PB02', 'BDinh');

-- --------------------------------------------------------

--
-- Table structure for table `phongban`
--

CREATE TABLE `phongban` (
  `IDPB` varchar(20) COLLATE utf8_unicode_ci NOT NULL,
  `mota` text COLLATE utf8_unicode_ci NOT NULL,
  `thoigian` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `phongban`
--

INSERT INTO `phongban` (`IDPB`, `mota`, `thoigian`) VALUES
('PB01', 'phong nhan su', '2018-12-12'),
('PB02', 'phong tu chuc', '2018-12-26'),
('PB03', 'phong ke hoach', '2018-12-12');

-- --------------------------------------------------------

--
-- Table structure for table `thongtinphong`
--

CREATE TABLE `thongtinphong` (
  `maphong` varchar(20) COLLATE utf8_unicode_ci NOT NULL,
  `loaiphong` text COLLATE utf8_unicode_ci NOT NULL,
  `songuoitoida` int(11) NOT NULL,
  `tinhtrang` text COLLATE utf8_unicode_ci NOT NULL,
  `tennguoidat` text COLLATE utf8_unicode_ci,
  `ngaydatphong` date DEFAULT NULL,
  `ngaytraphong` date DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `thongtinphong`
--

INSERT INTO `thongtinphong` (`maphong`, `loaiphong`, `songuoitoida`, `tinhtrang`, `tennguoidat`, `ngaydatphong`, `ngaytraphong`) VALUES
('STD001', 'STD', 4, 'Đã đặt', 'Đặng Văn Lâm', '2018-12-20', '2018-12-21'),
('STD002', 'STD', 4, 'Đã đặt', 'Nguyễn Công Phượng', '2018-12-18', '2018-12-20'),
('STD003', 'STD', 4, ' Đã đặt', 'Đinh Quang Duy', '2018-12-12', '2018-12-21'),
('STD004', 'STD', 2, 'Trống', NULL, NULL, NULL),
('VIP001', 'VIP', 4, ' Đã đặt', 'Nguyễn Văn Mạnh', '2018-12-13', '2018-12-26'),
('VIP002', 'VIP', 4, 'Đã đặt', 'Phan Văn Đức', '2018-12-18', '2018-12-26'),
('VIP003', 'VIP', 4, 'Trống', NULL, NULL, NULL),
('VIP004', 'VIP', 4, 'Trống', NULL, NULL, NULL);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `admin`
--
ALTER TABLE `admin`
  ADD PRIMARY KEY (`Username`);

--
-- Indexes for table `customer`
--
ALTER TABLE `customer`
  ADD PRIMARY KEY (`User`);

--
-- Indexes for table `loaiphong`
--
ALTER TABLE `loaiphong`
  ADD PRIMARY KEY (`maloaiphong`);

--
-- Indexes for table `nhanvien`
--
ALTER TABLE `nhanvien`
  ADD PRIMARY KEY (`IDNV`);

--
-- Indexes for table `phongban`
--
ALTER TABLE `phongban`
  ADD PRIMARY KEY (`IDPB`);

--
-- Indexes for table `thongtinphong`
--
ALTER TABLE `thongtinphong`
  ADD PRIMARY KEY (`maphong`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
