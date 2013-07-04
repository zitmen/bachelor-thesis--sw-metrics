<?xml version="1.0" encoding="utf-8" ?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns="http://www.w3.org/1999/xhtml" version="2.0">
	<xsl:import href="../checker.xsl" />
	<xsl:output method="xml" indent="yes" version="1.0" encoding="utf-8" />
	
	<xsl:template name="test">
		<!-- CHECK DATA TYPE -->
		<xsl:call-template name="check">
			<xsl:with-param name="description">Type: LongLong</xsl:with-param>
			<xsl:with-param name="condition" select="//class[@name='CompilationUnit']/member[@name='fragments']/item[@index='0']//class[@name='VariableDefinition']//class/@name='LongLong'" />
		</xsl:call-template>
		<!-- CHECK SIGN -->
		<xsl:call-template name="check">
			<xsl:with-param name="description">Sign: unsigned</xsl:with-param>
			<xsl:with-param name="condition" select="//class[@name='CompilationUnit']/member[@name='fragments']/item[@index='0']//class[@name='VariableDefinition']//class[@name='LongLong']/member[@name='isSigned']/text()='false'" />
		</xsl:call-template>
		<!-- CHECK VARIABLE NAME -->
		<xsl:call-template name="check">
			<xsl:with-param name="description">Name: foo</xsl:with-param>
			<xsl:with-param name="condition" select="//class[@name='CompilationUnit']/member[@name='fragments']/item[@index='0']//class[@name='VariableDefinition']//member[@name='identifierName']//member[@name='nameString']/text()='foo'" />
		</xsl:call-template>
		<!-- CHECK VARIABLE VALUE -->
		<xsl:call-template name="check">
			<xsl:with-param name="description">Value: 5</xsl:with-param>
			<xsl:with-param name="condition" select="//class[@name='CompilationUnit']/member[@name='fragments']/item[@index='0']//class[@name='VariableDefinition']//member[@name='initialValue']//class[@name='IntegerLiteral']//member[@name='value']/text()='5'" />
		</xsl:call-template>
	</xsl:template>
	
</xsl:stylesheet>