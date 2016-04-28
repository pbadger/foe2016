<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="7.5.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
<layer number="99" name="SpiceOrder" color="5" fill="1" visible="no" active="no"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="foe-scale">
<packages>
<package name="LTC1945-QFN">
<smd name="IN" x="0" y="-0.5" dx="0.25" dy="1.7" layer="1"/>
<smd name="CTS" x="0.5" y="-0.5" dx="0.25" dy="1.7" layer="1"/>
<smd name="IS-" x="1" y="-0.5" dx="0.25" dy="1.7" layer="1"/>
<smd name="IS+" x="1.5" y="-0.5" dx="0.25" dy="1.7" layer="1"/>
<smd name="IMON" x="2" y="-0.5" dx="0.25" dy="1.7" layer="1"/>
<smd name="NTC" x="2.5" y="-0.5" dx="0.25" dy="1.7" layer="1"/>
<smd name="IN1" x="-1.65" y="1.4" dx="0.25" dy="1.7" layer="1" rot="R90"/>
<smd name="SW1" x="-1.65" y="1.9" dx="0.25" dy="1.7" layer="1" rot="R90"/>
<smd name="SW2" x="-1.65" y="2.4" dx="0.25" dy="1.7" layer="1" rot="R90"/>
<smd name="IN2" x="-1.65" y="2.9" dx="0.25" dy="1.7" layer="1" rot="R90"/>
<smd name="DTH" x="4.15" y="1.4" dx="0.25" dy="1.7" layer="1" rot="R90"/>
<smd name="STAT" x="4.15" y="1.9" dx="0.25" dy="1.7" layer="1" rot="R90"/>
<smd name="FTH" x="4.15" y="2.4" dx="0.25" dy="1.7" layer="1" rot="R90"/>
<smd name="PTH2" x="4.15" y="2.9" dx="0.25" dy="1.7" layer="1" rot="R90"/>
<smd name="GND" x="0" y="4.6" dx="0.25" dy="1.7" layer="1"/>
<smd name="~EN" x="0.5" y="4.6" dx="0.25" dy="1.7" layer="1"/>
<smd name="CTD" x="1" y="4.6" dx="0.25" dy="1.7" layer="1"/>
<smd name="FB" x="1.5" y="4.6" dx="0.25" dy="1.7" layer="1"/>
<smd name="PTHM" x="2" y="4.6" dx="0.25" dy="1.7" layer="1"/>
<smd name="PTH1" x="2.5" y="4.6" dx="0.25" dy="1.7" layer="1"/>
<wire x1="3.7" y1="0" x2="3.7" y2="4.1" width="0.1" layer="21"/>
<wire x1="-1.1" y1="4.1" x2="-1.1" y2="0" width="0.1" layer="21"/>
<circle x="0" y="0.7" radius="0.22360625" width="0.1" layer="21"/>
<smd name="P$1" x="1.248621875" y="2.058896875" dx="3.65" dy="2.65" layer="1"/>
<wire x1="-1.090546875" y1="0.020065625" x2="3.663415625" y2="0.020065625" width="0.127" layer="22"/>
<wire x1="3.663415625" y1="0.020065625" x2="3.711859375" y2="0.04013125" width="0.127" layer="22" curve="45"/>
<wire x1="3.71853125" y1="4.09626875" x2="-1.08036875" y2="4.09626875" width="0.127" layer="22"/>
<wire x1="-1.08036875" y1="4.09626875" x2="-1.10055" y2="4.087909375" width="0.127" layer="22" curve="45"/>
</package>
<package name="LTC4120-4.2V">
<wire x1="-1.5" y1="-1.5" x2="1.5" y2="-1.5" width="0.05" layer="21"/>
<wire x1="1.5" y1="-1.5" x2="1.5" y2="1.5" width="0.05" layer="21"/>
<wire x1="1.5" y1="1.5" x2="-1.5" y2="1.5" width="0.05" layer="21"/>
<wire x1="-1.5" y1="1.5" x2="-1.5" y2="-1.5" width="0.05" layer="21"/>
<smd name="GND2" x="0" y="0" dx="1.45" dy="1.45" layer="1"/>
<smd name="INT_VCC" x="-0.75" y="-1.75" dx="0.25" dy="1" layer="1" rot="R180"/>
<smd name="BOOST" x="-0.25" y="-1.75" dx="0.25" dy="1" layer="1" rot="R180"/>
<smd name="IN" x="0.25" y="-1.75" dx="0.25" dy="1" layer="1" rot="R180"/>
<smd name="SW" x="0.75" y="-1.75" dx="0.25" dy="1" layer="1" rot="R180"/>
<smd name="GND" x="1.75" y="-0.75" dx="0.25" dy="1" layer="1" rot="R270"/>
<smd name="DHC" x="1.75" y="-0.25" dx="0.25" dy="1" layer="1" rot="R270"/>
<smd name="FREQ" x="1.75" y="0.25" dx="0.25" dy="1" layer="1" rot="R270"/>
<smd name="CHGSNS" x="1.75" y="0.75" dx="0.25" dy="1" layer="1" rot="R270"/>
<smd name="BAT" x="0.75" y="1.75" dx="0.25" dy="1" layer="1"/>
<smd name="BATSNS" x="0.25" y="1.75" dx="0.25" dy="1" layer="1"/>
<smd name="NC" x="-0.25" y="1.75" dx="0.25" dy="1" layer="1"/>
<smd name="NTC" x="-0.75" y="1.75" dx="0.25" dy="1" layer="1"/>
<smd name="PROG" x="-1.75" y="0.75" dx="0.25" dy="1" layer="1" rot="R90"/>
<smd name="~CHRG" x="-1.75" y="0.25" dx="0.25" dy="1" layer="1" rot="R90"/>
<smd name="~FAULT" x="-1.75" y="-0.25" dx="0.25" dy="1" layer="1" rot="R90"/>
<smd name="RUN" x="-1.75" y="-0.75" dx="0.25" dy="1" layer="1" rot="R90"/>
<circle x="-0.75" y="-1" radius="0.079071875" width="0.05" layer="21"/>
</package>
<package name="TQFP32-08">
<description>&lt;B&gt;Thin Plasic Quad Flat Package&lt;/B&gt; Grid 0.8 mm</description>
<wire x1="3.505" y1="3.505" x2="3.505" y2="-3.505" width="0.1524" layer="21"/>
<wire x1="3.505" y1="-3.505" x2="-3.505" y2="-3.505" width="0.1524" layer="21"/>
<wire x1="-3.505" y1="-3.505" x2="-3.505" y2="3.15" width="0.1524" layer="21"/>
<wire x1="-3.15" y1="3.505" x2="3.505" y2="3.505" width="0.1524" layer="21"/>
<wire x1="-3.15" y1="3.505" x2="-3.505" y2="3.15" width="0.1524" layer="21"/>
<circle x="-2.7432" y="2.7432" radius="0.3592" width="0.1524" layer="21"/>
<smd name="1" x="-4.9276" y="2.8" dx="2.54" dy="0.5588" layer="1"/>
<smd name="2" x="-4.9276" y="2" dx="2.54" dy="0.5588" layer="1"/>
<smd name="3" x="-4.9276" y="1.2" dx="2.54" dy="0.5588" layer="1"/>
<smd name="4" x="-4.9276" y="0.4" dx="2.54" dy="0.5588" layer="1"/>
<smd name="5" x="-4.9276" y="-0.4" dx="2.54" dy="0.5588" layer="1"/>
<smd name="6" x="-4.9276" y="-1.2" dx="2.54" dy="0.5588" layer="1"/>
<smd name="7" x="-4.9276" y="-2" dx="2.54" dy="0.5588" layer="1"/>
<smd name="8" x="-4.9276" y="-2.8" dx="2.54" dy="0.5588" layer="1"/>
<smd name="9" x="-2.8" y="-4.9276" dx="0.5588" dy="2.54" layer="1"/>
<smd name="10" x="-2" y="-4.9276" dx="0.5588" dy="2.54" layer="1"/>
<smd name="11" x="-1.2" y="-4.9276" dx="0.5588" dy="2.54" layer="1"/>
<smd name="12" x="-0.4" y="-4.9276" dx="0.5588" dy="2.54" layer="1"/>
<smd name="13" x="0.4" y="-4.9276" dx="0.5588" dy="2.54" layer="1"/>
<smd name="14" x="1.2" y="-4.9276" dx="0.5588" dy="2.54" layer="1"/>
<smd name="15" x="2" y="-4.9276" dx="0.5588" dy="2.54" layer="1"/>
<smd name="16" x="2.8" y="-4.9276" dx="0.5588" dy="2.54" layer="1"/>
<smd name="17" x="4.9276" y="-2.8" dx="2.54" dy="0.5588" layer="1"/>
<smd name="18" x="4.9276" y="-2" dx="2.54" dy="0.5588" layer="1"/>
<smd name="19" x="4.9276" y="-1.2" dx="2.54" dy="0.5588" layer="1"/>
<smd name="20" x="4.9276" y="-0.4" dx="2.54" dy="0.5588" layer="1"/>
<smd name="21" x="4.9276" y="0.4" dx="2.54" dy="0.5588" layer="1"/>
<smd name="22" x="4.9276" y="1.2" dx="2.54" dy="0.5588" layer="1"/>
<smd name="23" x="4.9276" y="2" dx="2.54" dy="0.5588" layer="1"/>
<smd name="24" x="4.9276" y="2.8" dx="2.54" dy="0.5588" layer="1"/>
<smd name="25" x="2.8" y="4.9276" dx="0.5588" dy="2.54" layer="1"/>
<smd name="26" x="2" y="4.9276" dx="0.5588" dy="2.54" layer="1"/>
<smd name="27" x="1.2" y="4.9276" dx="0.5588" dy="2.54" layer="1"/>
<smd name="28" x="0.4" y="4.9276" dx="0.5588" dy="2.54" layer="1"/>
<smd name="29" x="-0.4" y="4.9276" dx="0.5588" dy="2.54" layer="1"/>
<smd name="30" x="-1.2" y="4.9276" dx="0.5588" dy="2.54" layer="1"/>
<smd name="31" x="-2" y="4.9276" dx="0.5588" dy="2.54" layer="1"/>
<smd name="32" x="-2.8" y="4.9276" dx="0.5588" dy="2.54" layer="1"/>
<text x="-2.7686" y="5.08" size="0.8128" layer="25">&gt;NAME</text>
<text x="-3.0226" y="-1.27" size="0.8128" layer="27">&gt;VALUE</text>
<rectangle x1="-4.5466" y1="2.5714" x2="-3.556" y2="3.0286" layer="51"/>
<rectangle x1="-4.5466" y1="1.7714" x2="-3.556" y2="2.2286" layer="51"/>
<rectangle x1="-4.5466" y1="0.9714" x2="-3.556" y2="1.4286" layer="51"/>
<rectangle x1="-4.5466" y1="0.1714" x2="-3.556" y2="0.6286" layer="51"/>
<rectangle x1="-4.5466" y1="-0.6286" x2="-3.556" y2="-0.1714" layer="51"/>
<rectangle x1="-4.5466" y1="-1.4286" x2="-3.556" y2="-0.9714" layer="51"/>
<rectangle x1="-4.5466" y1="-2.2286" x2="-3.556" y2="-1.7714" layer="51"/>
<rectangle x1="-4.5466" y1="-3.0286" x2="-3.556" y2="-2.5714" layer="51"/>
<rectangle x1="-3.0286" y1="-4.5466" x2="-2.5714" y2="-3.556" layer="51"/>
<rectangle x1="-2.2286" y1="-4.5466" x2="-1.7714" y2="-3.556" layer="51"/>
<rectangle x1="-1.4286" y1="-4.5466" x2="-0.9714" y2="-3.556" layer="51"/>
<rectangle x1="-0.6286" y1="-4.5466" x2="-0.1714" y2="-3.556" layer="51"/>
<rectangle x1="0.1714" y1="-4.5466" x2="0.6286" y2="-3.556" layer="51"/>
<rectangle x1="0.9714" y1="-4.5466" x2="1.4286" y2="-3.556" layer="51"/>
<rectangle x1="1.7714" y1="-4.5466" x2="2.2286" y2="-3.556" layer="51"/>
<rectangle x1="2.5714" y1="-4.5466" x2="3.0286" y2="-3.556" layer="51"/>
<rectangle x1="3.556" y1="-3.0286" x2="4.5466" y2="-2.5714" layer="51"/>
<rectangle x1="3.556" y1="-2.2286" x2="4.5466" y2="-1.7714" layer="51"/>
<rectangle x1="3.556" y1="-1.4286" x2="4.5466" y2="-0.9714" layer="51"/>
<rectangle x1="3.556" y1="-0.6286" x2="4.5466" y2="-0.1714" layer="51"/>
<rectangle x1="3.556" y1="0.1714" x2="4.5466" y2="0.6286" layer="51"/>
<rectangle x1="3.556" y1="0.9714" x2="4.5466" y2="1.4286" layer="51"/>
<rectangle x1="3.556" y1="1.7714" x2="4.5466" y2="2.2286" layer="51"/>
<rectangle x1="3.556" y1="2.5714" x2="4.5466" y2="3.0286" layer="51"/>
<rectangle x1="2.5714" y1="3.556" x2="3.0286" y2="4.5466" layer="51"/>
<rectangle x1="1.7714" y1="3.556" x2="2.2286" y2="4.5466" layer="51"/>
<rectangle x1="0.9714" y1="3.556" x2="1.4286" y2="4.5466" layer="51"/>
<rectangle x1="0.1714" y1="3.556" x2="0.6286" y2="4.5466" layer="51"/>
<rectangle x1="-0.6286" y1="3.556" x2="-0.1714" y2="4.5466" layer="51"/>
<rectangle x1="-1.4286" y1="3.556" x2="-0.9714" y2="4.5466" layer="51"/>
<rectangle x1="-2.2286" y1="3.556" x2="-1.7714" y2="4.5466" layer="51"/>
<rectangle x1="-3.0286" y1="3.556" x2="-2.5714" y2="4.5466" layer="51"/>
</package>
</packages>
<symbols>
<symbol name="LTC1425-POWERTRANSMITTER">
<pin name="IN" x="-17.78" y="12.7" length="middle"/>
<pin name="CTS" x="-17.78" y="7.62" length="middle"/>
<pin name="IS-" x="-17.78" y="2.54" length="middle"/>
<pin name="IS+" x="-17.78" y="-2.54" length="middle"/>
<pin name="IMON" x="-17.78" y="-7.62" length="middle"/>
<pin name="NTC" x="-17.78" y="-12.7" length="middle"/>
<pin name="DTH" x="-5.08" y="-20.32" length="middle" rot="R90"/>
<pin name="STAT" x="0" y="-20.32" length="middle" rot="R90"/>
<pin name="FTH" x="5.08" y="-20.32" length="middle" rot="R90"/>
<pin name="PTH2" x="10.16" y="-20.32" length="middle" rot="R90"/>
<pin name="PTH1" x="22.86" y="-12.7" length="middle" rot="R180"/>
<pin name="PTHM" x="22.86" y="-7.62" length="middle" rot="R180"/>
<pin name="FB" x="22.86" y="-2.54" length="middle" rot="R180"/>
<pin name="CTD" x="22.86" y="2.54" length="middle" rot="R180"/>
<pin name="~EN" x="22.86" y="7.62" length="middle" rot="R180"/>
<pin name="GND" x="22.86" y="12.7" length="middle" rot="R180"/>
<pin name="IN2" x="10.16" y="20.32" length="middle" rot="R270"/>
<pin name="SW2" x="5.08" y="20.32" length="middle" rot="R270"/>
<pin name="SW1" x="0" y="20.32" length="middle" rot="R270"/>
<pin name="IN1" x="-5.08" y="20.32" length="middle" rot="R270"/>
<wire x1="-17.78" y1="-20.32" x2="22.86" y2="-20.32" width="0.254" layer="94"/>
<wire x1="22.86" y1="-20.32" x2="22.86" y2="20.32" width="0.254" layer="94"/>
<wire x1="22.86" y1="20.32" x2="-17.78" y2="20.32" width="0.254" layer="94"/>
<wire x1="-17.78" y1="20.32" x2="-17.78" y2="-20.32" width="0.254" layer="94"/>
<text x="0" y="2.54" size="1.778" layer="94">LTC4125</text>
</symbol>
<symbol name="LTC4120">
<pin name="INT_VCC" x="-7.62" y="7.62" length="middle"/>
<pin name="BOOST" x="-7.62" y="2.54" length="middle"/>
<pin name="IN" x="-7.62" y="-2.54" length="middle"/>
<pin name="SW" x="-7.62" y="-7.62" length="middle"/>
<pin name="GND" x="5.08" y="-20.32" length="middle" rot="R90"/>
<pin name="DHC" x="10.16" y="-20.32" length="middle" rot="R90"/>
<pin name="FREQ" x="15.24" y="-20.32" length="middle" rot="R90"/>
<pin name="CHGSNS" x="20.32" y="-20.32" length="middle" rot="R90"/>
<pin name="BAT" x="33.02" y="-7.62" length="middle" rot="R180"/>
<pin name="BATSNS" x="33.02" y="-2.54" length="middle" rot="R180"/>
<pin name="NC" x="33.02" y="2.54" length="middle" rot="R180"/>
<pin name="NTC" x="33.02" y="7.62" length="middle" rot="R180"/>
<pin name="PROG" x="20.32" y="20.32" length="middle" rot="R270"/>
<pin name="~CHRG" x="15.24" y="20.32" length="middle" rot="R270"/>
<pin name="~FAULT" x="10.16" y="20.32" length="middle" rot="R270"/>
<pin name="RUN" x="5.08" y="20.32" length="middle" rot="R270"/>
<wire x1="-7.62" y1="20.32" x2="-7.62" y2="-20.32" width="0.254" layer="94"/>
<wire x1="-7.62" y1="-20.32" x2="33.02" y2="-20.32" width="0.254" layer="94"/>
<wire x1="33.02" y1="-20.32" x2="33.02" y2="20.32" width="0.254" layer="94"/>
<wire x1="33.02" y1="20.32" x2="-7.62" y2="20.32" width="0.254" layer="94"/>
<text x="27.94" y="22.86" size="1.778" layer="94">LTC4120-4.2V</text>
<pin name="GND2" x="0" y="-20.32" length="middle" rot="R90"/>
</symbol>
<symbol name="SAMD21E">
<wire x1="-10.16" y1="7.62" x2="-10.16" y2="-43.18" width="0.254" layer="94"/>
<pin name="PA00" x="-15.24" y="2.54" length="middle"/>
<pin name="PA01" x="-15.24" y="-2.54" length="middle"/>
<pin name="PA02" x="-15.24" y="-7.62" length="middle"/>
<pin name="PA03" x="-15.24" y="-12.7" length="middle"/>
<pin name="PA04" x="-15.24" y="-17.78" length="middle"/>
<pin name="PA05" x="-15.24" y="-22.86" length="middle"/>
<pin name="PA06" x="-15.24" y="-27.94" length="middle"/>
<pin name="PA07" x="-15.24" y="-33.02" length="middle"/>
<pin name="VDDANA" x="-5.08" y="-48.26" length="middle" rot="R90"/>
<pin name="GND" x="0" y="-48.26" length="middle" rot="R90"/>
<pin name="PA08" x="5.08" y="-48.26" length="middle" rot="R90"/>
<pin name="PA09" x="10.16" y="-48.26" length="middle" rot="R90"/>
<pin name="PA10" x="15.24" y="-48.26" length="middle" rot="R90"/>
<pin name="PA11" x="20.32" y="-48.26" length="middle" rot="R90"/>
<pin name="PA14" x="25.4" y="-48.26" length="middle" rot="R90"/>
<pin name="PA15" x="30.48" y="-48.26" length="middle" rot="R90"/>
<wire x1="-10.16" y1="-43.18" x2="40.64" y2="-43.18" width="0.254" layer="94"/>
<wire x1="40.64" y1="-43.18" x2="40.64" y2="7.62" width="0.254" layer="94"/>
<wire x1="40.64" y1="7.62" x2="-10.16" y2="7.62" width="0.254" layer="94"/>
<pin name="PA16" x="45.72" y="-38.1" length="middle" rot="R180"/>
<pin name="PA17" x="45.72" y="-33.02" length="middle" rot="R180"/>
<pin name="PA18" x="45.72" y="-27.94" length="middle" rot="R180"/>
<pin name="PA19" x="45.72" y="-22.86" length="middle" rot="R180"/>
<pin name="PA22" x="45.72" y="-17.78" length="middle" rot="R180"/>
<pin name="PA23" x="45.72" y="-12.7" length="middle" rot="R180"/>
<pin name="PA24" x="45.72" y="-7.62" length="middle" rot="R180"/>
<pin name="PA25" x="45.72" y="-2.54" length="middle" rot="R180"/>
<pin name="PA27" x="35.56" y="12.7" length="middle" rot="R270"/>
<pin name="RESETN" x="30.48" y="12.7" length="middle" rot="R270"/>
<pin name="PA28" x="25.4" y="12.7" length="middle" rot="R270"/>
<pin name="GND2" x="20.32" y="12.7" length="middle" rot="R270"/>
<pin name="VDDCORE" x="15.24" y="12.7" length="middle" rot="R270"/>
<pin name="VDDIN" x="10.16" y="12.7" length="middle" rot="R270"/>
<pin name="PA30" x="5.08" y="12.7" length="middle" rot="R270"/>
<pin name="PA31" x="0" y="12.7" length="middle" rot="R270"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="LTC4125">
<gates>
<gate name="G$1" symbol="LTC1425-POWERTRANSMITTER" x="2.54" y="5.08"/>
</gates>
<devices>
<device name="" package="LTC1945-QFN">
<connects>
<connect gate="G$1" pin="CTD" pad="CTD"/>
<connect gate="G$1" pin="CTS" pad="CTS"/>
<connect gate="G$1" pin="DTH" pad="DTH"/>
<connect gate="G$1" pin="FB" pad="FB"/>
<connect gate="G$1" pin="FTH" pad="FTH"/>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="IMON" pad="IMON"/>
<connect gate="G$1" pin="IN" pad="IN"/>
<connect gate="G$1" pin="IN1" pad="IN1"/>
<connect gate="G$1" pin="IN2" pad="IN2"/>
<connect gate="G$1" pin="IS+" pad="IS+"/>
<connect gate="G$1" pin="IS-" pad="IS-"/>
<connect gate="G$1" pin="NTC" pad="NTC"/>
<connect gate="G$1" pin="PTH1" pad="PTH1"/>
<connect gate="G$1" pin="PTH2" pad="PTH2"/>
<connect gate="G$1" pin="PTHM" pad="PTHM"/>
<connect gate="G$1" pin="STAT" pad="STAT"/>
<connect gate="G$1" pin="SW1" pad="SW1"/>
<connect gate="G$1" pin="SW2" pad="SW2"/>
<connect gate="G$1" pin="~EN" pad="~EN"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="LTC4120-4.2V">
<gates>
<gate name="G$1" symbol="LTC4120" x="-12.7" y="0"/>
</gates>
<devices>
<device name="" package="LTC4120-4.2V">
<connects>
<connect gate="G$1" pin="BAT" pad="BAT"/>
<connect gate="G$1" pin="BATSNS" pad="BATSNS"/>
<connect gate="G$1" pin="BOOST" pad="BOOST"/>
<connect gate="G$1" pin="CHGSNS" pad="CHGSNS"/>
<connect gate="G$1" pin="DHC" pad="DHC"/>
<connect gate="G$1" pin="FREQ" pad="FREQ"/>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="GND2" pad="GND2"/>
<connect gate="G$1" pin="IN" pad="IN"/>
<connect gate="G$1" pin="INT_VCC" pad="INT_VCC"/>
<connect gate="G$1" pin="NC" pad="NC"/>
<connect gate="G$1" pin="NTC" pad="NTC"/>
<connect gate="G$1" pin="PROG" pad="PROG"/>
<connect gate="G$1" pin="RUN" pad="RUN"/>
<connect gate="G$1" pin="SW" pad="SW"/>
<connect gate="G$1" pin="~CHRG" pad="~CHRG"/>
<connect gate="G$1" pin="~FAULT" pad="~FAULT"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="SAMD21E" prefix="U6">
<gates>
<gate name="G$1" symbol="SAMD21E" x="-15.24" y="15.24"/>
</gates>
<devices>
<device name="" package="TQFP32-08">
<connects>
<connect gate="G$1" pin="GND" pad="10"/>
<connect gate="G$1" pin="GND2" pad="28"/>
<connect gate="G$1" pin="PA00" pad="1"/>
<connect gate="G$1" pin="PA01" pad="2"/>
<connect gate="G$1" pin="PA02" pad="3"/>
<connect gate="G$1" pin="PA03" pad="4"/>
<connect gate="G$1" pin="PA04" pad="5"/>
<connect gate="G$1" pin="PA05" pad="6"/>
<connect gate="G$1" pin="PA06" pad="7"/>
<connect gate="G$1" pin="PA07" pad="8"/>
<connect gate="G$1" pin="PA08" pad="11"/>
<connect gate="G$1" pin="PA09" pad="12"/>
<connect gate="G$1" pin="PA10" pad="13"/>
<connect gate="G$1" pin="PA11" pad="14"/>
<connect gate="G$1" pin="PA14" pad="15"/>
<connect gate="G$1" pin="PA15" pad="16"/>
<connect gate="G$1" pin="PA16" pad="17"/>
<connect gate="G$1" pin="PA17" pad="18"/>
<connect gate="G$1" pin="PA18" pad="19"/>
<connect gate="G$1" pin="PA19" pad="20"/>
<connect gate="G$1" pin="PA22" pad="21"/>
<connect gate="G$1" pin="PA23" pad="22"/>
<connect gate="G$1" pin="PA24" pad="23"/>
<connect gate="G$1" pin="PA25" pad="24"/>
<connect gate="G$1" pin="PA27" pad="25"/>
<connect gate="G$1" pin="PA28" pad="27"/>
<connect gate="G$1" pin="PA30" pad="31"/>
<connect gate="G$1" pin="PA31" pad="32"/>
<connect gate="G$1" pin="RESETN" pad="26"/>
<connect gate="G$1" pin="VDDANA" pad="9"/>
<connect gate="G$1" pin="VDDCORE" pad="29"/>
<connect gate="G$1" pin="VDDIN" pad="30"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="U$1" library="foe-scale" deviceset="LTC4125" device=""/>
<part name="U$2" library="foe-scale" deviceset="LTC4120-4.2V" device=""/>
<part name="U1" library="foe-scale" deviceset="SAMD21E" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="U$1" gate="G$1" x="33.02" y="60.96"/>
<instance part="U$2" gate="G$1" x="180.34" y="60.96"/>
<instance part="U1" gate="G$1" x="22.86" y="-35.56"/>
</instances>
<busses>
</busses>
<nets>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
