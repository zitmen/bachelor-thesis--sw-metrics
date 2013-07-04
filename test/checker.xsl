<?xml version="1.0" encoding="utf-8" ?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns="http://www.w3.org/1999/xhtml" version="2.0">
	<xsl:output method="xml" indent="yes" version="1.0" encoding="utf-8" />
	
	<xsl:template match="/">
		<xsl:element name="html" namespace="http://www.w3.org/1999/xhtml">
			<xsl:attribute name="lang">en</xsl:attribute>
			<xsl:element name="head">
				<xsl:element name="meta">
					<xsl:attribute name="http-equiv">content-type</xsl:attribute>
					<xsl:attribute name="content">text/html; charset=utf-8</xsl:attribute>
				</xsl:element>
				<xsl:element name="title">
					<xsl:text>ASTM checker</xsl:text>
				</xsl:element>
				<xsl:element name="style">
					<xsl:attribute name="type">text/css</xsl:attribute>
					<xsl:text>
						body { font-family: Tahoma; }
						p { font-size: 20px; }
					</xsl:text>
				</xsl:element>
			</xsl:element>
			<xsl:element name="body">
				<xsl:element name="h1">
					<xsl:text>Checking results:</xsl:text>
				</xsl:element>
				<xsl:call-template name="test" />
			</xsl:element>
		</xsl:element>
	</xsl:template>
	
	<xsl:template name="check">
		<xsl:param name="description" />
		<xsl:param name="condition" />
		<xsl:element name="p">
			<xsl:value-of select="$description" />
			<xsl:text> [</xsl:text>
			<xsl:element name="strong">
				<xsl:choose>
					<xsl:when test="$condition">
						<xsl:attribute name="style">color:darkgreen;</xsl:attribute>
						<xsl:text>OK</xsl:text>
					</xsl:when>
					<xsl:otherwise>
						<xsl:attribute name="style">color:darkred;</xsl:attribute>
						<xsl:text>FAILED</xsl:text>
					</xsl:otherwise>
				</xsl:choose>
			</xsl:element>
			<xsl:text>]</xsl:text>
		</xsl:element>
	</xsl:template>
	
</xsl:stylesheet>