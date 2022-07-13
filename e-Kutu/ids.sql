-- phpMyAdmin SQL Dump
-- version 5.0.2
-- https://www.phpmyadmin.net/
--
-- Anamakine: 127.0.0.1
-- Üretim Zamanı: 10 Haz 2020, 21:40:11
-- Sunucu sürümü: 10.4.11-MariaDB
-- PHP Sürümü: 7.4.5

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Veritabanı: `ids`
--

-- --------------------------------------------------------

--
-- Tablo için tablo yapısı `kullanicilar`
--

CREATE TABLE `kullanicilar` (
  `kId` int(11) NOT NULL,
  `kAdi` varchar(100) COLLATE utf8_unicode_ci NOT NULL,
  `kSifre` varchar(200) COLLATE utf8_unicode_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Tablo döküm verisi `kullanicilar`
--

INSERT INTO `kullanicilar` (`kId`, `kAdi`, `kSifre`) VALUES
(1, 'admin', 'a1r5t256'),
(2, 'admin1', '12345');

-- --------------------------------------------------------

--
-- Tablo için tablo yapısı `sicakliklar`
--

CREATE TABLE `sicakliklar` (
  `sID` int(11) NOT NULL,
  `sTime` int(11) NOT NULL,
  `sTemp` int(11) NOT NULL,
  `sIp` varchar(50) COLLATE utf8_unicode_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Tablo döküm verisi `sicakliklar`
--

INSERT INTO `sicakliklar` (`sID`, `sTime`, `sTemp`, `sIp`) VALUES
(7, 1591289156, 34, '127.0.0.1'),
(8, 1591289162, 35, '127.0.0.1'),
(9, 1591289173, 28, '127.0.0.1'),
(10, 1591289180, 27, '127.0.0.1'),
(11, 1591289186, 24, '127.0.0.1'),
(12, 1591289198, 27, '127.0.0.1'),
(13, 1591289202, 26, '127.0.0.1'),
(14, 1591289204, 26, '127.0.0.1'),
(15, 1591289208, 29, '127.0.0.1'),
(16, 1591289215, 33, '127.0.0.1');

--
-- Dökümü yapılmış tablolar için indeksler
--

--
-- Tablo için indeksler `kullanicilar`
--
ALTER TABLE `kullanicilar`
  ADD PRIMARY KEY (`kId`),
  ADD UNIQUE KEY `kAdi` (`kAdi`);

--
-- Tablo için indeksler `sicakliklar`
--
ALTER TABLE `sicakliklar`
  ADD PRIMARY KEY (`sID`);

--
-- Dökümü yapılmış tablolar için AUTO_INCREMENT değeri
--

--
-- Tablo için AUTO_INCREMENT değeri `kullanicilar`
--
ALTER TABLE `kullanicilar`
  MODIFY `kId` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- Tablo için AUTO_INCREMENT değeri `sicakliklar`
--
ALTER TABLE `sicakliklar`
  MODIFY `sID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=17;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
