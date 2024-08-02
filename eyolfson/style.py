from pygments.style import Style
from pygments.token import (
    Token,
    Text,
    Whitespace,
    Escape,
    Error,
    Other,
    Keyword,
    Name,
    Literal,
    String,
    Number,
    Punctuation,
    Operator,
    Comment,
    Generic,
)

# Token
## Text
### Whitespace
## Escape
## Error
## Other
## Keyword
### Keyword.Constant
### Keyword.Declaration
### Keyword.Namespace
### Keyword.Pseudo
### Keyword.Reserved
### Keyword.Type
## Name
### Name.Attribute
### Name.Builtin
### Name.Builtin.Pseudo
### Name.Class
### Name.Constant
### Name.Decorator
### Name.Entity
### Name.Exception
### Name.Function
### Name.Property
### Name.Label
### Name.Namespace
### Name.Other
### Name.Tag
### Name.Variable
### Name.Variable.Class
### Name.Variable.Global
### Name.Variable.Instance
## Literal
### Literal.Date
### String
#### String.Backtick
#### String.Char
#### String.Doc
#### String.Double
#### String.Escape
#### String.Heredoc
#### String.Interpol
#### String.Other
#### String.Regex
#### String.Single
#### String.Symbol
### Number
#### Number.Bin
#### Number.Float
#### Number.Hex
#### Number.Integer
#### Number.Integer.Long
#### Number.Oct
## Punctuation
## Operator
### Operator.Word
## Comment
### Comment.Hashbang
### Comment.Multiline
### Comment.Preproc
### Comment.PreprocFile
### Comment.Single
### Comment.Special
## Generic
### Generic.Deleted
### Generic.Emph
### Generic.Error
### Generic.Heading
### Generic.Inserted
### Generic.Output
### Generic.Prompt
### Generic.Strong
### Generic.Subheading
### Generic.Traceback

RED = '#dc4633'
BLUE = '#008bb0'
CYAN = '#00a189'
GREEN = '#8dbf2e'
MAGENTA = '#ab1368'
YELLOW = '#f1c500'
GRAY = '#d0d1c9'

class EyolfsonStyle(Style):
    styles = {
        Token: '',
        Comment: GREEN,
        Comment.Preproc: MAGENTA,
        Comment.PreprocFile: CYAN,
        Keyword: MAGENTA,
        Keyword.Type: BLUE,
        Name: '',
        Name.Class: BLUE,
        Name.Function: GREEN,
        Literal: CYAN,
        Error: RED,
    }
