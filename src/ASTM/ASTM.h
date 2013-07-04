/*!
 * \file
 * ASTM.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 *
 * Index of entire ASTM. All nodes and node identifiers are included.
 */
#ifndef	_ASTM_H_
#define	_ASTM_H_

#include "AccessKind.h"
#include "ActualParameter.h"
#include "Add.h"
#include "AddressOf.h"
#include "AggregateExpression.h"
#include "AggregateScope.h"
#include "AggregateType.h"
#include "AggregateTypeDefinition.h"
#include "And.h"
#include "AnnotationExpression.h"
#include "AnnotationType.h"
#include "ArrayAccess.h"
#include "ArrayType.h"
#include "Assign.h"
#include "Auto.h"
#include "BinaryExpression.h"
#include "BinaryOperator.h"
#include "BitAnd.h"
#include "BitFieldDefinition.h"
#include "BitLeftShift.h"
#include "BitNot.h"
#include "BitOr.h"
#include "BitRightShift.h"
#include "BitXor.h"
#include "BlockScope.h"
#include "BlockStatement.h"
#include "Boolean.h"
#include "BooleanLiteral.h"
#include "BreakStatement.h"
#include "ByReferenceFormalParameterType.h"
#include "ByValueFormalParameterType.h"
#include "Byte.h"
#include "CaseBlock.h"
#include "CastExpression.h"
#include "CatchBlock.h"
#include "CharLiteral.h"
#include "Character.h"
#include "ClassType.h"
#include "CollectionType.h"
#include "Comment.h"
#include "CompilationUnit.h"
#include "ConditionalExpression.h"
#include "ConstructedType.h"
#include "ContinueStatement.h"
#include "DataDefinition.h"
#include "DataType.h"
#include "Declaration.h"
#include "DeclarationOrDefinition.h"
#include "DeclarationOrDefinitionStatement.h"
#include "Decrement.h"
#include "DefaultBlock.h"
#include "Definition.h"
#include "DefinitionUnit.h"
#include "DeleteStatement.h"
#include "Deref.h"
#include "DerivesFrom.h"
#include "Dimension.h"
#include "Divide.h"
#include "DoWhileStatement.h"
#include "Double.h"
#include "EmptyStatement.h"
#include "EntryDefinition.h"
#include "EnumLiteralDefinition.h"
#include "EnumType.h"
#include "Equal.h"
#include "ExceptionType.h"
#include "Exponent.h"
#include "Expression.h"
#include "ExpressionStatement.h"
#include "External.h"
#include "Float.h"
#include "FormalParameterDeclaration.h"
#include "ForStatement.h"
#include "FormalParameterDefinition.h"
#include "FormalParameterType.h"
#include "FunctionCallExpression.h"
#include "FunctionDeclaration.h"
#include "FunctionDefinition.h"
#include "FunctionMemberAttributes.h"
#include "FunctionScope.h"
#include "FunctionType.h"
#include "GASTMObject.h"
#include "GASTMSemanticObject.h"
#include "GASTMSourceObject.h"
#include "GASTMSyntaxObject.h"
#include "GlobalScope.h"
#include "Greater.h"
#include "IdentifierReference.h"
#include "IfStatement.h"
#include "IncludeUnit.h"
#include "Increment.h"
#include "Integer.h"
#include "IntegerLiteral.h"
#include "JumpStatement.h"
#include "LabelAccess.h"
#include "LabelDefinition.h"
#include "LabelType.h"
#include "LabeledStatement.h"
#include "Less.h"
#include "Literal.h"
#include "LongDouble.h"
#include "LongInteger.h"
#include "LongLong.h"
#include "LoopStatement.h"
#include "MacroCall.h"
#include "MacroDefinition.h"
#include "Modulus.h"
#include "Multiply.h"
#include "Name.h"
#include "NameReference.h"
#include "NameSpaceDefinition.h"
#include "NameSpaceScope.h"
#include "NameSpaceType.h"
#include "NamedType.h"
#include "NamedTypeDefinition.h"
#include "NamedTypeReference.h"
#include "NewExpression.h"
#include "NonVirtual.h"
#include "Not.h"
#include "NotEqual.h"
#include "NotGreater.h"
#include "NotLess.h"
#include "OperatorAssign.h"
#include "Or.h"
#include "OtherSyntaxObject.h"
#include "PointerType.h"
#include "PostDecrement.h"
#include "PostIncrement.h"
#include "PreprocessorElement.h"
#include "PrimitiveType.h"
#include "Private.h"
#include "ProgramScope.h"
#include "Project.h"
#include "Protected.h"
#include "Public.h"
#include "PureVirtual.h"
#include "QualifiedIdentifierReference.h"
#include "QualifiedOverData.h"
#include "QualifiedOverPointer.h"
#include "RangeExpression.h"
#include "RangeType.h"
#include "RealLiteral.h"
#include "ReferenceType.h"
#include "ReturnStatement.h"
#include "Scope.h"
#include "ShortInteger.h"
#include "SourceFile.h"
#include "SourceLocation.h"
#include "Statement.h"
#include "Static.h"
#include "StorageSpecification.h"
#include "String.h"
#include "StringLiteral.h"
#include "StructureType.h"
#include "Subtract.h"
#include "SwitchCase.h"
#include "SwitchStatement.h"
#include "TryStatement.h"
#include "Type.h"
#include "TypeDefinition.h"
#include "TypeQualifiedIdentifierReference.h"
#include "TypeReference.h"
#include "UnaryExpression.h"
#include "UnaryOperator.h"
#include "UnaryMinus.h"
#include "UnaryPlus.h"
#include "UnionType.h"
#include "UnnamedTypeReference.h"
#include "VariableDeclaration.h"
#include "VariableDefinition.h"
#include "Virtual.h"
#include "VirtualSpecification.h"
#include "Void.h"
#include "WhileStatement.h"
#include "WideCharacter.h"

#include "NodeId.h"

#endif	// _ASTM_H_