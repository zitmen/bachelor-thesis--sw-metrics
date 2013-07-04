<?xml version="1.0" encoding="utf-8" ?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns="http://www.w3.org/1999/xhtml" version="2.0">
	<xsl:import href="../checker.xsl" />
	<xsl:output method="xml" indent="yes" version="1.0" encoding="utf-8" />
	
	<xsl:template name="test">
		<!-- CHECK FUNCTION RETURN TYPE -->
		<xsl:call-template name="check">
			<xsl:with-param name="description">Function return type: Integer</xsl:with-param>
			<xsl:with-param name="condition" select="//class[@name='CompilationUnit']/member[@name='fragments']/item[@index='0']//class[@name='FunctionDefinition']//member[@name='type']//class[@name='Integer']" />
		</xsl:call-template>
		
		<!-- CHECK FUNCTION NAME -->
		<xsl:call-template name="check">
			<xsl:with-param name="description">Function name: fnFoo</xsl:with-param>
			<xsl:with-param name="condition" select="//class[@name='CompilationUnit']/member[@name='fragments']/item[@index='0']//class[@name='FunctionDefinition']//member[@name='identifierName']//member[@name='nameString']/text()='fnFoo'" />
		</xsl:call-template>
		
		<!-- CHECK FUNCTION PARAMETERS -->
			<!-- CHECK 1st PARAMETER'S TYPE -->
			<xsl:call-template name="check">
				<xsl:with-param name="description">Param 1 type: int</xsl:with-param>
				<xsl:with-param name="condition" select="//class[@name='CompilationUnit']/member[@name='fragments']/item[@index='0']//class[@name='FunctionDefinition']//member[@name='formalParameters']/item[@index='0']//class[@name='FormalParameterDefinition']/member[@name='type']//class[@name='Integer']" />
			</xsl:call-template>
			<!-- CHECK 1st PARAMETER'S NAME -->
			<xsl:call-template name="check">
				<xsl:with-param name="description">Param 1 name: a</xsl:with-param>
				<xsl:with-param name="condition" select="//class[@name='CompilationUnit']/member[@name='fragments']/item[@index='0']//class[@name='FunctionDefinition']//member[@name='formalParameters']/item[@index='0']//class[@name='FormalParameterDefinition']/member[@name='identifierName']//member[@name='nameString']/text()='a'" />
			</xsl:call-template>
			<!-- CHECK 1st PARAMETER'S VALUE -->
			<xsl:call-template name="check">
				<xsl:with-param name="description">Param 1 value: 5</xsl:with-param>
				<xsl:with-param name="condition" select="//class[@name='CompilationUnit']/member[@name='fragments']/item[@index='0']//class[@name='FunctionDefinition']//member[@name='formalParameters']/item[@index='0']//class[@name='FormalParameterDefinition']/member[@name='initialValue']/class[@name='IntegerLiteral']/member[@name='value']/text()='5'" />
			</xsl:call-template>
			
			<!-- CHECK 2nd PARAMETER'S TYPE -->
			<xsl:call-template name="check">
				<xsl:with-param name="description">Param 2 type: double</xsl:with-param>
				<xsl:with-param name="condition" select="//class[@name='CompilationUnit']/member[@name='fragments']/item[@index='0']//class[@name='FunctionDefinition']//member[@name='formalParameters']/item[@index='1']//class[@name='FormalParameterDefinition']/member[@name='type']//class[@name='Double']" />
			</xsl:call-template>
			<!-- CHECK 2nd PARAMETER'S NAME -->
			<xsl:call-template name="check">
				<xsl:with-param name="description">Param 2 name: b</xsl:with-param>
				<xsl:with-param name="condition" select="//class[@name='CompilationUnit']/member[@name='fragments']/item[@index='0']//class[@name='FunctionDefinition']//member[@name='formalParameters']/item[@index='1']//class[@name='FormalParameterDefinition']/member[@name='identifierName']//member[@name='nameString']/text()='b'" />
			</xsl:call-template>
			<!-- CHECK 2nd PARAMETER'S VALUE -->
			<xsl:call-template name="check">
				<xsl:with-param name="description">Param 2 value: 2.3</xsl:with-param>
				<xsl:with-param name="condition" select="//class[@name='CompilationUnit']/member[@name='fragments']/item[@index='0']//class[@name='FunctionDefinition']//member[@name='formalParameters']/item[@index='1']//class[@name='FormalParameterDefinition']/member[@name='initialValue']/class[@name='RealLiteral']/member[@name='value']/text()='2.3'" />
			</xsl:call-template>
			
			<!-- CHECK 3rd PARAMETER'S NAME -->
			<xsl:call-template name="check">
				<xsl:with-param name="description">Param 3 name: ...</xsl:with-param>
				<xsl:with-param name="condition" select="//class[@name='CompilationUnit']/member[@name='fragments']/item[@index='0']//class[@name='FunctionDefinition']//member[@name='formalParameters']/item[@index='2']//class[@name='FormalParameterDefinition']/member[@name='identifierName']//member[@name='nameString']/text()='...'" />
			</xsl:call-template>
			
		<!-- CHECK FUNCTION BODY -->
			<!-- CHECK RETURN VALUE -->
			<xsl:call-template name="check">
				<xsl:with-param name="description">Return value: 0</xsl:with-param>
				<xsl:with-param name="condition" select="//class[@name='CompilationUnit']/member[@name='fragments']/item[@index='0']//class[@name='FunctionDefinition']//member[@name='body']//class[@name='BlockStatement']//class[@name='ReturnStatement']/member[@name='returnValue']/class[@name='IntegerLiteral']/member[@name='value']/text()='0'" />
			</xsl:call-template>
			
	</xsl:template>
</xsl:stylesheet>